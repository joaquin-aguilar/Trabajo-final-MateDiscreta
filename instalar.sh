#!/bin/bash

# Colores para mensajes
VERDE='\033[0;32m'
ROJO='\033[0;31m'
NC='\033[0m' # Sin color

echo -e "${VERDE}🛠️  Iniciando build...${NC}"

# Eliminar ultima instalacion
if [ -d "instalacion" ]; then
    echo -e "${VERDE}🧹 Limpiando carpeta de instalaciones...${NC}"
    rm -rf instalacion
fi

# Crear carpeta de builds limpia
if [ -d "builds" ]; then
    echo -e "${VERDE}🧹 Limpiando carpeta de builds...${NC}"
    rm -rf builds
fi
mkdir builds
cd builds || exit

# Ejecutar CMake
echo -e "${VERDE}📦 Configurando CMake...${NC}"
cmake .. -DCMAKE_BUILD_TYPE=Release

if [ $? -ne 0 ]; then
    echo -e "${ROJO}❌ Error en configuración de CMake${NC}"
    exit 1
fi

# Compilar
echo -e "${VERDE}🔨 Compilando...${NC}"
cmake --build . -- -j$(nproc)

if [ $? -ne 0 ]; then
    echo -e "${ROJO}❌ Error en compilación${NC}"
    exit 1
fi

# Instalar
echo -e "${VERDE}📦 Instalando en ../instalacion/...${NC}"
cmake --install . --prefix ../instalacion

if [ $? -ne 0 ]; then
    echo -e "${ROJO}❌ Error en instalación${NC}"
    exit 1
fi

echo -e "${VERDE}✅ Build e instalación completadas con éxito.${NC}"
echo -e "${VERDE}🚀 Ejecuta con:${NC} ./instalacion/bin/aplicacion_de_relaciones.out"
