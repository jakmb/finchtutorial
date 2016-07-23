To compile a new program, first all the name of your cpp file that contains main to the MAIN_CPP_FILES variable on line 29 of the makefile. 
Next add any other cpp files that are used to the OTHER_CPP_FILES on line 30 of the makefile. 
Next add any header files you're using to the HFILES variable on line 32. 
Running 'make' from the FinchC++ directory should now produce an executable for all the programs in MAIN_CPP_FILES to the exes folder in the FinchC++ folder.

Note for Windows: If you are running windows you need to either add the hidapi.dll file to the directory you are running your executable from or copy the dll to the Windows\System32 directory. This dll is used to allow for HID connections to the Finch. 