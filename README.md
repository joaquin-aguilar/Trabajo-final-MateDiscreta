# Dependencias:
### Este proyecto utiliza:
- [Graphviz](graphviz.org) para la generación de imágenes.
- [Make](www.gnu.org/software/make/) y [CMake](https://cmake.org/) para la compilación multiplataforma.

### Puedes instalar los paquetes necesarios en los repositorios oficiales de las distribuciones GNU/LINUX
### Fedora:
$ dnf install make cmake graphviz

### Debian:
$ apt-get install make cmake graphviz

### En Windows 
Necesitarás un emulador de entornos POSIX como MSYS2 (UCRT64):

$ pacman -S cmake mingw-w64-ucrt-x86_64-gtk4 

Además, deberás descargar:
- [Graphviz](https://graphviz.org/download/)

> [!NOTE]
> Tambien debes añadir la carpeta de binarios de msys2 al Path (por defecto en "C:\msys64\ucrt64\bin")
  
# Construcción automatizada usando scripts:
> [!TIP]
> El ejecutable .sh es para bash Linux/MacOS, tambien es compatible con windows bajo msys2

### Compilar e instalar 

$ ./instalar.sh