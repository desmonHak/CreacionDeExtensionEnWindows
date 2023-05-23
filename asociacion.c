#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void asociarExtension(const char* extension, const char* programa, const char* icono) {
    HKEY hkey;
    char clave[256];
    
    // Crear la clave de la extensión
    sprintf(clave, ".%s", extension);
    if (RegCreateKey(HKEY_CLASSES_ROOT, clave, &hkey) == ERROR_SUCCESS) {
        RegSetValueEx(hkey, NULL, 0, REG_SZ, (BYTE*)extension, strlen(extension));
        RegCloseKey(hkey);
    }

    // Crear la clave de shell y command
    sprintf(clave, "%s\\shell\\open\\command", extension);
    if (RegCreateKey(HKEY_CLASSES_ROOT, clave, &hkey) == ERROR_SUCCESS) {
        RegSetValueEx(hkey, NULL, 0, REG_SZ, (BYTE*)programa, strlen(programa));
        RegCloseKey(hkey);
    }

    // Crear la clave para el icono
    sprintf(clave, "%s\\DefaultIcon", extension);
    if (RegCreateKey(HKEY_CLASSES_ROOT, clave, &hkey) == ERROR_SUCCESS) {
        RegSetValueEx(hkey, NULL, 0, REG_SZ, (BYTE*)icono, strlen(icono));
        RegCloseKey(hkey);
    }
}

int main() {
    const char* extension = "uwu";
    const char* batchFile = "C:\\Users\\Desmon0x90\\Desktop\\openuwu.bat";
    char comando[MAX_PATH + 10];  // 10 caracteres adicionales para espacio extra
    const char* icono = "C:\\Users\\Desmon0x90\\Desktop\\icono.ico";  // Reemplaza con la ruta al archivo de icono

    
    // Construir el comando completo con la ruta del archivo por lotes y el argumento "%1"
    sprintf(comando, "\"%s\" \"%%1\"", batchFile);
    printf("\"%s\"\n", comando);


    // Asociar la extensión con el comando
    asociarExtension(extension, comando, icono);

    return 0;
}
