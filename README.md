# Dependencias:

## Graphviz (para la generación de imágenes)
### Revisar la [página oficial](https://graphviz.org/download/)    
## Make (para facilitar la compilación y ejecución)
### puedes en los repositorios oficiales de las distribuciones GNU/LINUX
Fedora:
    
    $ dnf install make
Debian: 
   
    $ sudo apt-get install make
### O puedes revisar la [página oficial](https://www.gnu.org/software/make/)


# Compilar usando gcc:
    $ gcc src/src.c -o builds/programa.out

# Ejecutar:
    $ ./builds/programa.out

# Compilar usando Make
    $ make

# Ejecutar usando Make:
    $ make run