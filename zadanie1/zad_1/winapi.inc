; --------------------[ PROTOTYPY I STA£E WYWO£AÑ WINAPI ] ------------------------
; ---------------------------------------------------------------------------------
; domyœlny uchwyt konsoli - sta³a zdewiniowana w WINAPI
STD_OUTPUT_HANDLE EQU -11 ; definicja sta³ej

; sta³e dostêpu do plików
GENERIC_READ EQU 80000000h ; sta³a definiuj¹ca dostêp do pliku w trybie do odczytu
GENERIC_WRITE EQU 40000000h ; tryb zapisu do pliku
; sta³e otwierania plików
OPEN_EXISTING EQU 3 ; otwórz plik, jeœli nie istnieje - b³¹d
CREATE_ALWAYS EQU 2 ; utwórz/nadpisz plik
; sta³e atrybutów
FILE_ATTRIBUTE_ARCHIVE EQU 20h
; sta³e b³êdów
INVALID_HANDLE_VALUE EQU -1

; sta³e alokacji pamiêci
MEM_COMMIT EQU 1000h ; alokuje zmiany w pamiêci
PAGE_READWRITE EQU 4h ; ustawia stronnicowanie pamiêci w trybie read/write
MEM_RELEASE EQU 8000h ; uwolnij okreœlony region stronnicowanej pamiêci 

; Nadpisanie aliansu z WINAPI - domyœlnie jest ustawione na przyjmowanie ASCII (WriteConsoleA)
WriteConsole EQU <WriteConsoleA>

CreateFileW PROTO, ; Tworzenie i odczyt plików
    lpFileName: DWORD,
    dwDesiredAccess: DWORD,
    dwShareMode: DWORD,
    lpSecurityAttributes: DWORD,
    dwCreationDisposition: DWORD,
    dwFlagsAndAttributes: DWORD,
    hTemplateFile: DWORD

GetFileSize PROTO, ; okreœl rozmiar pliku
    hFile: DWORD,
    lpFileSizeHigh: DWORD ; opcjonalne

VirtualAlloc PROTO, ; odpowienik calloc, dla wirtualnego stronnicowania
    lpAddress: DWORD, ; opcjonalne
    dwSize: DWORD,
    flAllocationType: DWORD,
    flProtect: DWORD

VirtualFree PROTO, ; zwolnij zaalokowan¹ pamiêæ
    _lpAddress: DWORD,
    _dwSize: DWORD,
    dwFreeType: DWORD

ReadFile PROTO, ; odczytaj plik z odpowiedniego portu I/O
    _hFile: DWORD,
    _lpBuffer: DWORD,
    nNumberOfBytesToRead: DWORD,
    lpNumberOfBytesRead: DWORD,
    lpOverlapped: DWORD

WriteFile PROTO, ; zapis do pliku na odpowiedni port I/O okreœlony przez "uchwyt" pliku
    ___hFile: DWORD,
    __lpBuffer: DWORD,
    _nNumberOfBytesToRead: DWORD,
    _lpNumberOfBytesRead: DWORD,
    _lpOverlapped: DWORD

CloseHandle PROTO, ; zamknij plik - zwolnienie uchwytu
    __hFile: DWORD

ExitProcess PROTO, ; odpowiednik return w WINAPI
    dwExitCode: DWORD

FreeConsole PROTO ; uwolnij konsolê

AllocConsole PROTO ; nowa konsola jest gotowa, Panie

GetStdHandle PROTO, ; zwróæ uchwyt konsoli do eax (akumulatora)
    nStdHandle: DWORD

WriteConsoleW PROTO,                     ; print do konsoli
    handle: DWORD,                       ; uchwyt
    lpBuffer: PTR BYTE,                  ; wskaŸnik na bufor
    nNumberOfBytesToWrite: DWORD,        ; rozmiar buforu
    lpNumberOfbytesWritten: PTR DWORD,   ; iloœæ znaków do wypisania
    lpReserved: DWORD                    ; ???

WriteConsole PROTO, ; prototyp funkcji dla ANSCII
    : DWORD,
    : PTR BYTE,
    : DWORD,
    : PTR DWORD,
    : DWORD

GetCommandLineW PROTO ; pobierz argumenty z wywo³ania programu

CommandLineToArgvW PROTO, ; przekonwertuj argumenty do listy
    lpCmdLine: DWORD,
    pNumArgs: PTR SWORD

lstrlenW PROTO, ; okreœl d³ugoœæ string'a
    lpString: DWORD
; ---------------------------------------------------------------------------------