; --------------------[ PROTOTYPY I STA�E WYWO�A� WINAPI ] ------------------------
; ---------------------------------------------------------------------------------
; domy�lny uchwyt konsoli - sta�a zdewiniowana w WINAPI
STD_OUTPUT_HANDLE EQU -11 ; definicja sta�ej

; sta�e dost�pu do plik�w
GENERIC_READ EQU 80000000h ; sta�a definiuj�ca dost�p do pliku w trybie do odczytu
GENERIC_WRITE EQU 40000000h ; tryb zapisu do pliku
; sta�e otwierania plik�w
OPEN_EXISTING EQU 3 ; otw�rz plik, je�li nie istnieje - b��d
CREATE_ALWAYS EQU 2 ; utw�rz/nadpisz plik
; sta�e atrybut�w
FILE_ATTRIBUTE_ARCHIVE EQU 20h
; sta�e b��d�w
INVALID_HANDLE_VALUE EQU -1

; sta�e alokacji pami�ci
MEM_COMMIT EQU 1000h ; alokuje zmiany w pami�ci
PAGE_READWRITE EQU 4h ; ustawia stronnicowanie pami�ci w trybie read/write
MEM_RELEASE EQU 8000h ; uwolnij okre�lony region stronnicowanej pami�ci 

; Nadpisanie aliansu z WINAPI - domy�lnie jest ustawione na przyjmowanie ASCII (WriteConsoleA)
WriteConsole EQU <WriteConsoleA>

CreateFileW PROTO, ; Tworzenie i odczyt plik�w
    lpFileName: DWORD,
    dwDesiredAccess: DWORD,
    dwShareMode: DWORD,
    lpSecurityAttributes: DWORD,
    dwCreationDisposition: DWORD,
    dwFlagsAndAttributes: DWORD,
    hTemplateFile: DWORD

GetFileSize PROTO, ; okre�l rozmiar pliku
    hFile: DWORD,
    lpFileSizeHigh: DWORD ; opcjonalne

VirtualAlloc PROTO, ; odpowienik calloc, dla wirtualnego stronnicowania
    lpAddress: DWORD, ; opcjonalne
    dwSize: DWORD,
    flAllocationType: DWORD,
    flProtect: DWORD

VirtualFree PROTO, ; zwolnij zaalokowan� pami��
    _lpAddress: DWORD,
    _dwSize: DWORD,
    dwFreeType: DWORD

ReadFile PROTO, ; odczytaj plik z odpowiedniego portu I/O
    _hFile: DWORD,
    _lpBuffer: DWORD,
    nNumberOfBytesToRead: DWORD,
    lpNumberOfBytesRead: DWORD,
    lpOverlapped: DWORD

WriteFile PROTO, ; zapis do pliku na odpowiedni port I/O okre�lony przez "uchwyt" pliku
    ___hFile: DWORD,
    __lpBuffer: DWORD,
    _nNumberOfBytesToRead: DWORD,
    _lpNumberOfBytesRead: DWORD,
    _lpOverlapped: DWORD

CloseHandle PROTO, ; zamknij plik - zwolnienie uchwytu
    __hFile: DWORD

ExitProcess PROTO, ; odpowiednik return w WINAPI
    dwExitCode: DWORD

FreeConsole PROTO ; uwolnij konsol�

AllocConsole PROTO ; nowa konsola jest gotowa, Panie

GetStdHandle PROTO, ; zwr�� uchwyt konsoli do eax (akumulatora)
    nStdHandle: DWORD

WriteConsoleW PROTO,                     ; print do konsoli
    handle: DWORD,                       ; uchwyt
    lpBuffer: PTR BYTE,                  ; wska�nik na bufor
    nNumberOfBytesToWrite: DWORD,        ; rozmiar buforu
    lpNumberOfbytesWritten: PTR DWORD,   ; ilo�� znak�w do wypisania
    lpReserved: DWORD                    ; ???

WriteConsole PROTO, ; prototyp funkcji dla ANSCII
    : DWORD,
    : PTR BYTE,
    : DWORD,
    : PTR DWORD,
    : DWORD

GetCommandLineW PROTO ; pobierz argumenty z wywo�ania programu

CommandLineToArgvW PROTO, ; przekonwertuj argumenty do listy
    lpCmdLine: DWORD,
    pNumArgs: PTR SWORD

lstrlenW PROTO, ; okre�l d�ugo�� string'a
    lpString: DWORD
; ---------------------------------------------------------------------------------