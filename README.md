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
Entornos POSIX como MSYS2:
$ pacman -S cmake mingw-w64-ucrt-x86_64-graphviz

Nativo (usando MinGW):
- [Descargas CMake](cmake.org/download/) 
- [Graphviz](https://graphviz.org/download/)
  
  
# Construcción automatizada usando scripts:
> 💡 El ejecutable .sh es para bash (Linux/MacOs) y el ejecutable .bat es comatiple con cmd y powershell
> 💡El script de instalacion creara una carpeta llamada "instalacion/" los binarios ejecutables estan dentro de "bin/"
### Compilar e instalar 
$ ./instalar.sh
### Ejecutar
$ ./instalacion/bin/aplicacion_de_relaciones 
# Construcción manual usando gcc:
> 💡 Considera que debes usar .exe (en lugar de .out) como convencion en un programa para windows!
### Compilar
$ gcc src/src.c src/libs/matriz_booleana.c src/libs/utils.c -o builds/programa.out 

 ### Ejecutar:
$ ./builds/programa.out
