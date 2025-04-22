echo off
setlocal enabledelayedexpansion
chcp 65001>nul

:: color 0A = fondo negro, texto verde claro
color 0A

echo 🛠️  Iniciando build...

:: Eliminar carpeta instalacion si existe
if exist instalacion (
    echo 🧹 Limpiando carpeta de instalaciones...
    rmdir /s /q instalacion
)

:: Eliminar carpeta builds si existe y crearla de nuevo
if exist builds (
    echo 🧹 Limpiando carpeta de builds...
    rmdir /s /q builds
)
mkdir builds
cd builds || exit /b

:: Ejecutar CMake (Forzamos el uso de GNU explicitamente para evitar errores de compilacion causados por MSVC)
echo 📦 Configurando CMake...
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release .. 
if errorlevel 1 (
    color 0C
    echo ❌ Error en configuración de CMake
    exit /b 1
)

:: Compilar
echo 🔨 Compilando...
cmake --build .

if errorlevel 1 (
    color 0C
    echo ❌ Error en compilación
    exit /b 1
)

:: Instalar
echo 📦 Instalando en ../instalacion/...
cmake --install .

if errorlevel 1 (
    color 0C
    echo ❌ Error en instalación
    exit /b 1
)

color 0A
echo ✅ Build e instalación completadas con éxito.
echo 🚀 Ejecuta con: .\instalacion\bin\aplicacion_de_relaciones.exe