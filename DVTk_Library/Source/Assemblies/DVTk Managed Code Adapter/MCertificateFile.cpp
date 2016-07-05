// ------------------------------------------------------
// DVTk - The Healthcare Validation Toolkit (www.dvtk.org)
// Copyright � 2009 DVTk
// ------------------------------------------------------
// This file is part of DVTk.
//
// DVTk is free software; you can redistribute it and/or modify it under the terms of the GNU
// Lesser General Public License as published by the Free Software Foundation; either version 3.0
// of the License, or (at your option) any later version. 
// 
// DVTk is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
// the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. 
// 
// You should have received a copy of the GNU Lesser General Public License along with this
// library; if not, see <http://www.gnu.org/licenses/>

#include "StdAfx.h"
#include ".\MCertificateFile.h"
#using <mscorlib.dll>

namespace Wrappers
{
    using namespace System::Runtime::InteropServices;

    MCertificateFile::MCertificateFile(
        Wrappers::WrappedSecurityItemType securityItemType,
        System::String __gc* pFileName,
        System::String __gc* pPassword)
    {
        char* pFileNameAnsiString = (char*)(void*)Marshal::StringToHGlobalAnsi(pFileName);
        char* pPasswordAnsiString = (char*)(void*)Marshal::StringToHGlobalAnsi(pPassword);
        DVT_STATUS dvtStatus = ::MSG_OK;
        m_pC = new CERTIFICATE_FILE_CLASS(
            pFileNameAnsiString,
            pPasswordAnsiString,
            NULL, // TODO: somehow get this logging info back to user as exceptions!
            dvtStatus);
        Marshal::FreeHGlobal(pFileNameAnsiString);
        Marshal::FreeHGlobal(pPasswordAnsiString);
        System::String __gc* pThrowMessage;
        switch (dvtStatus)
        {
        case ::MSG_OK:
            break;
        case ::MSG_LIB_NOT_EXIST:
            switch (securityItemType)
            {
            case Wrappers::WrappedSecurityItemType::Credential:
                pThrowMessage =
                    System::String::Concat(
                    S"The Secure Socket Library is not available.",
                    S"Will not be able to view or modify the credentials file contents");
                throw new Wrappers::Exceptions::SecureSocketLibraryNotAvailableException(pThrowMessage);
            case Wrappers::WrappedSecurityItemType::Certificate:
                pThrowMessage =
                    System::String::Concat(
                    S"The Secure Socket Library is not available.",
                    S"Will not be able to view or modify the credentials file contents");
                throw new Wrappers::Exceptions::SecureSocketLibraryNotAvailableException(pThrowMessage);
            default:
                System::Diagnostics::Trace::Assert(false);
            }
        case ::MSG_ERROR:
            switch (securityItemType)
            {
            case Wrappers::WrappedSecurityItemType::Credential:
                pThrowMessage = S"Error opening security credentials file";
                throw new Wrappers::Exceptions::CredentialFileLoadExpection(pThrowMessage);
            case Wrappers::WrappedSecurityItemType::Certificate:
                pThrowMessage = S"Error opening trusted certificate file";
                throw new Wrappers::Exceptions::CertificateFileLoadExpection(pThrowMessage);
            default:
                System::Diagnostics::Trace::Assert(false);
			}
        case ::MSG_INVALID_PASSWORD:
            switch (securityItemType)
            {
            case Wrappers::WrappedSecurityItemType::Credential:
                pThrowMessage =
                    System::String::Concat(
                    S"Invalid Password for security credentials file \"",
                    pFileName,
                    S"\"");
                throw new Wrappers::Exceptions::PasswordExpection(pThrowMessage);
            case Wrappers::WrappedSecurityItemType::Certificate:
                pThrowMessage =
                    System::String::Concat(
                    S"Invalid Password",
                    S"The file \"",
                    pFileName,
                    S"\" cannot be used directly by DVT as a trusted certificate file.",
                    S"Select a new or existing trusted certificate file and use the Add Certificate button to ",
                    S"add the certificates from \"",
                    pFileName,
                    S"\" to the trusted certificates.");
                throw new Wrappers::Exceptions::PasswordExpection(pThrowMessage);
            default:
                System::Diagnostics::Trace::Assert(false);
            }
        case ::MSG_FILE_NOT_EXIST:
            /* Allow in memory creation of a new file
            switch (securityItemType)
            {
            case Wrappers::WrappedSecurityItemType::Credential:
                pThrowMessage = S"Security credentials file does not exist";
                throw new Wrappers::Exceptions::CredentialFileDoesNotExistExpection(pThrowMessage);
            case Wrappers::WrappedSecurityItemType::Certificate:
                pThrowMessage = S"Trusted certificate file does not exist";
                throw new Wrappers::Exceptions::CertificateFileDoesNotExistExpection(pThrowMessage);
            default:
                System::Diagnostics::Trace::Assert(false);
            }
            */
            break;
        default:
            System::Diagnostics::Trace::Assert(false);
        }
    }

    MCertificateFile::~MCertificateFile(void)
    {
        delete m_pC;
    }

    void MCertificateFile::AddCertificate(
        Wrappers::WrappedSecurityItemType securityItemType,
        System::String __gc* pFileName,
        System::String __gc* pPassword)
    {
        System::Boolean bCertificatesOnly =
            (securityItemType == Wrappers::WrappedSecurityItemType::Certificate);
        char* pFileNameAnsiString = (char*)(void*)Marshal::StringToHGlobalAnsi(pFileName);
        char* pPasswordAnsiString = (char*)(void*)Marshal::StringToHGlobalAnsi(pPassword);
        DVT_STATUS dvtStatus =
            this->m_pC->importCertificateFile(
            pFileNameAnsiString,
            bCertificatesOnly,
            pPasswordAnsiString);
        Marshal::FreeHGlobal(pFileNameAnsiString);
        Marshal::FreeHGlobal(pPasswordAnsiString);
        switch (dvtStatus)
        {
        case ::MSG_OK:
            break;
        case ::MSG_NO_VALUE:
            switch (securityItemType)
            {
            case Wrappers::WrappedSecurityItemType::Credential:
                throw new Wrappers::Exceptions::CredentialFileLoadExpection(
                    "No certificate was found in the given file");
            case Wrappers::WrappedSecurityItemType::Certificate:
                throw new Wrappers::Exceptions::CertificateFileLoadExpection(
                    "No certificate was found in the given file");
            default:
                System::Diagnostics::Trace::Assert(false);
            }
        case ::MSG_FILE_NOT_EXIST:
            switch (securityItemType)
            {
            case Wrappers::WrappedSecurityItemType::Credential:
                throw new Wrappers::Exceptions::CertificateFileLoadExpection(
                    "The credential file does not exist");
            case Wrappers::WrappedSecurityItemType::Certificate:
                throw new Wrappers::Exceptions::CertificateFileLoadExpection(
                    "The certificate file does not exist");
            default:
                System::Diagnostics::Trace::Assert(false);
            }
        case ::MSG_INVALID_PASSWORD:
            throw new Wrappers::Exceptions::PasswordExpection(
                "Invalid Password");
        case ::MSG_ERROR:
            switch (securityItemType)
            {
            case Wrappers::WrappedSecurityItemType::Credential:
                throw new Wrappers::Exceptions::CredentialFileLoadExpection(
                    "Error importing credentials");
            case Wrappers::WrappedSecurityItemType::Certificate:
                throw new Wrappers::Exceptions::CertificateFileLoadExpection(
                    "Error importing certificate");
            default:
                System::Diagnostics::Trace::Assert(false);
            }
        default:
            System::Diagnostics::Trace::Assert(false);
        }
    }

    System::UInt32 MCertificateFile::get_NumberOfCertificates()
    {
        return m_pC->getNumberOfCertificates();
    }

    System::Boolean MCertificateFile::RemoveCertificate(System::UInt32 index)
    {
        return this->m_pC->removeCertificate(index);
    }

    Wrappers::MCertificate __gc* MCertificateFile::get_Certificate(System::UInt32 index)
    {
        CERTIFICATE_CLASS* pCERTIFICATE_CLASS = m_pC->getCertificate(index);
        Wrappers::MCertificate __gc* pCertificate = new Wrappers::MCertificate();
        pCertificate->Wrap(pCERTIFICATE_CLASS);
        return pCertificate;
    }

    System::String __gc* MCertificateFile::get_Password()
    {
        // Implicit marshalling from const char* to System::String by Managed C++ compiler.
        return m_pC->getPassword();
    }

    System::Boolean MCertificateFile::get_HasChanged()
    {
        return m_pC->hasChanged();
    }

    void MCertificateFile::WriteFile(System::String __gc* pPassword)
    {
        char* pPasswordAnsiString = (char*)(void*)Marshal::StringToHGlobalAnsi(pPassword);
        System::Boolean success = this->m_pC->writeFile(pPasswordAnsiString);
        Marshal::FreeHGlobal(pPasswordAnsiString);
        if (!success) throw new System::ApplicationException();
    }

    System::Boolean MCertificateFile::Verify(
        Wrappers::WrappedSecurityItemType securityItemType,
        [System::Runtime::InteropServices::Out] System::String __gc*__gc* ppVerificationMessage)
    {
        char* msgPtr = NULL;
        bool isCredentials = 
            (securityItemType == Wrappers::WrappedSecurityItemType::Credential);
        bool bResult = this->m_pC->verify(isCredentials, &msgPtr);
        *ppVerificationMessage = msgPtr;
        return bResult;
    }
}