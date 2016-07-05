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
#include ".\MDefinition.h"
#include < vcclr.h >
#using <mscorlib.dll>

namespace Wrappers
{
    using namespace System::Runtime::InteropServices;

    MDefinitionFileDetails 
        MDefinition::get_FileDetails(System::String __gc* pFileName)
    {
        DEF_DETAILS_CLASS retDEF_DETAILS_CLASS;
        std::string sFileName;
		bool success = false;

        Wrappers::MarshalString(pFileName, sFileName);

		try
		{
			success = DEFINITION->GetDetails(sFileName, retDEF_DETAILS_CLASS);
		}
		catch(char* exception)
		{
			throw new System::ApplicationException(exception);
		}

		if (!success) 
		{
			throw new System::ApplicationException("Definition File Not Found");
		}

        MDefinitionFileDetails definitionFileDetails;

		// Application Entity name.
		definitionFileDetails.AEName = retDEF_DETAILS_CLASS.GetAEName().c_str();

		if (definitionFileDetails.AEName->Length == 0)
		{
			throw new System::ApplicationException("Application Entity name is empty.");
		}

		// Application Entity version.
		definitionFileDetails.AEVersion = retDEF_DETAILS_CLASS.GetAEVersion().c_str();

		if (definitionFileDetails.AEVersion->Length  == 0)
		{
			throw new System::ApplicationException("Application Entity version is empty.");
		}

		// SOP Class name.
		definitionFileDetails.SOPClassName = retDEF_DETAILS_CLASS.GetSOPClassName().c_str();

		if (definitionFileDetails.SOPClassName->Length == 0)
		{
			throw new System::ApplicationException("SOP Class name is empty.");
		}

		//  SOP Class UID.
		definitionFileDetails.SOPClassUID = retDEF_DETAILS_CLASS.GetSOPClassUID().c_str();

		if (definitionFileDetails.SOPClassUID->Length == 0)
		{
			throw new System::ApplicationException("SOP Class UID is empty.");
		}

		// Is meta SOP class.
		definitionFileDetails.IsMetaSOPClass = retDEF_DETAILS_CLASS.GetIsMetaSOPClass();

        return definitionFileDetails;
    }
}