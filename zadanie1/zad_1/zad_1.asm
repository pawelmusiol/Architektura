;   @title: Zad 1
;   @version: x86
;   @author: Pawel Musiol
;   @date: 

.486 ; ustawienie zbioru instrukcji na procesor intel 80486, czyli programujemy na 32 bitowej architekturze
.model flat, stdcall ; ustawienie modelu pamiêci i wywo³añ funkcji na standard z jêzyka C
.stack 1024 ; wielkoœæ stosu; domyœlnie to 1024 bajty w Windows

include winapi.inc ; do³¹czenie pliku nag³ówkowego zawieraj¹cego definicje funkcji z WinApi

.const	
	err1 BYTE "Blad otwarcia pliku", 0
	err2 BYTE "Blad odczytu pliku", 0
	err3 BYTE "Blad alokacji pliku", 0
	errArgc1 BYTE "not enough args", 0
	errArgc2 BYTE "too many args", 0
	newLine DWORD 0ah, 0dh, 0

.data
	hInstance DWORD 0 ; uchwyt okna konsoli
	fName DWORD	0
	hFile DWORD	0
	fSize DWORD	0
	fBuff DWORD	0
	argv DWORD 0
	argc DWORD 0
.code

	main proc ; pocz¹tek procedury (funkcji)
		INVOKE AllocConsole ; konsola ju¿ na nas czeka, Panie
		INVOKE GetStdHandle, STD_OUTPUT_HANDLE ; potrzebujemy jej uchwytu (ID)
		mov hInstance, eax ; uchwyt umieszczamy w bloku pamiêci hInstance

		; TODO: zad 1

		INVOKE GetCommandLineW
		INVOKE CommandLineToArgvW, eax, OFFSET argc
		mov argv, eax
		mov edi, eax
		add edi, 4
		xor ecx, ecx
		inc ecx

		.IF	argc < 2 
			INVOKE WriteConsole, hInstance, ADDR errArgc1, (LENGTHOF errArgc1) - 1, 0, 0 
			jmp	@end
		.ENDIF
		.IF argc > 3 ;sprawdza czy liczba argumentów jest odpowiednia
			INVOKE WriteConsole, hInstance, ADDR errArgc2, (LENGTHOF errArgc2) - 1, 0, 0 
			jmp	@end
		.ENDIF	
		
		
			mov	eax, [edi]
			mov ebx, eax
			add edi, 4
			push ecx
				

					.IF argc == 2
						INVOKE CreateFileW, ebx, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0
						mov hFile, eax
					.ENDIF
					.IF argc == 3
						INVOKE CreateFileW, ebx, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0
						mov hFile, eax
						



					.ENDIF
					
					INVOKE GetFileSize, hFile, 0
					mov fSize, eax
					
					INVOKE VirtualAlloc, 0, eax, MEM_COMMIT, PAGE_READWRITE
					mov fBuff, eax

					INVOKE ReadFile, hFile, eax, fSize, 0, 0

					.IF argc == 2
						INVOKE WriteConsoleW, hInstance, fBuff, fSize, 0, 0
					jmp @end
					.ENDIF

			pop ecx
			inc ecx

			mov	eax, [edi]
			mov ebx, eax
			add edi, 4
			push ecx

				.IF argc == 3
					
				INVOKE lstrlenW, eax
				mov ecx, 2
				mul ecx

					INVOKE WriteFile, hFile, ebx, eax, 0, 0
					jmp @end
				.ENDIF

			pop ecx

		@end:
		INVOKE VirtualFree, fBuff, ADDR fSize, MEM_RELEASE 
		INVOKE CloseHandle, hFile
		INVOKE FreeConsole ; uwolniæ konsolê!
		INVOKE ExitProcess, 0 ; zakoñcz proces z kodem 0
	main endp ; koniec procedury main
END main ; ustaw procedurê (funkcje) startow¹ oraz koniec programu