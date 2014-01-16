#include <windows.h>
#include <fstream>
#include <iomanip>
#include "psapi.h"

#pragma comment ( lib, "psapi.lib" )

using namespace std ;


int main( )
{
    ofstream fout ( "EnumProcessAndModule.txt" ) ;

    DWORD dwProcessId[1024], cbNeededProcess;

    if ( !EnumProcesses( dwProcessId, sizeof(dwProcessId), &cbNeededProcess ) )
        return 0;

    for ( unsigned int i = 0; i < ( cbNeededProcess/sizeof(DWORD) ); i++ )
	{
		char szProcessName[MAX_PATH] = "unknown";

		HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                                   PROCESS_VM_READ,
                                   FALSE, dwProcessId[i] );
		if ( NULL != hProcess )
		{					
			HMODULE hMods[1024];
			DWORD cbNeededModule ;

			if ( EnumProcessModules( hProcess, hMods, sizeof(hMods), &cbNeededModule ) )
			{
				PROCESS_MEMORY_COUNTERS ProcessMemCounters ;

				GetProcessMemoryInfo ( hProcess, &ProcessMemCounters, sizeof(ProcessMemCounters) ) ;

				fout << "ProcessId : " << dwProcessId[i] << endl ;
				fout << "Process Memory information:" << endl ;
				fout << "PageFaultCount                 :" << hex << setw(8) << ProcessMemCounters.PageFaultCount		<< endl ;
				fout << "PeakWorkingSetSize             :" << hex << setw(8) << ProcessMemCounters.PeakWorkingSetSize	<< endl ;
				fout << "WorkingSetSize                 :" << hex << setw(8) << ProcessMemCounters.WorkingSetSize		<< endl ;
				fout << "QuotaPeakPagedPoolUsage        :" << hex << setw(8) << ProcessMemCounters.QuotaPeakPagedPoolUsage	<< endl ;
				fout << "QuotaPagedPoolUsage            :" << hex << setw(8) << ProcessMemCounters.QuotaPagedPoolUsage	<< endl ;
				fout << "QuotaPeakNonPagedPoolUsage     :" << hex << setw(8) << ProcessMemCounters.QuotaPeakNonPagedPoolUsage	<< endl ;
				fout << "QuotaNonPagedPoolUsage         :" << hex << setw(8) << ProcessMemCounters.QuotaNonPagedPoolUsage	<< endl ;
				fout << "PagefileUsage                  :" << hex << setw(8) << ProcessMemCounters.PagefileUsage		<< endl ;
				fout << "PeakPagefileUsage              :" << hex << setw(8) << ProcessMemCounters.PeakPagefileUsage		<< endl ;

				for ( unsigned int j = 0; j < ( cbNeededModule/sizeof(DWORD) ); j++ )	
				{					
					char szModuleName[MAX_PATH];

					if ( GetModuleFileNameEx ( hProcess, hMods[j], szModuleName, sizeof(szModuleName) ) )
					{
						fout << '\t' << szModuleName << setw(8) << hex << "(0x" << hMods[j] << ")" << endl ;

                    	                            MODULEINFO ModuleInfo ;

						if ( GetModuleInformation ( hProcess, hMods[j], &ModuleInfo, sizeof(ModuleInfo) ) )
						{
							fout << "\t\tBaseOfDll   : " << ModuleInfo.lpBaseOfDll << endl ;
							fout << "\t\tSizeOfImage : " << ModuleInfo.SizeOfImage << endl ;
							fout << "\t\tEntryPoint  : " << ModuleInfo.EntryPoint  << endl ;
						}
					 }
                                     }

				fout << endl << endl ;
			}

			 CloseHandle( hProcess );
		}
			
	}

	return 0 ;
}