# Mock-Exam-SO
---
## Esquema a utilizar para las colas:
RR(1), RR(3), SJF.

## ⚙️ Sistema de Compilación y Estructura

Este proyecto utiliza **CMake** como herramienta de automatización para gestionar la configuración, generación y enlace del código fuente de manera multiplataforma. 

La arquitectura del proyecto está organizada de forma modular bajo la siguiente estructura de directorios:

* **`Mock-Exam-SO/`**: Raíz del proyecto.  
├── **`.gitignore`**: Archivo que indica a Git qué archivos o carpetas debe ignorar (como binarios o temporales).  
├── **`bin/`**: Contiene los archivos ejecutables y binarios finales generados tras la compilación.  
├── **`build/`**: Carpeta temporal donde **CMake** genera los archivos intermedios de construcción (Makefiles, objetos).  
├── **`docs/`**: Alberga la documentación adicional del proyecto, enunciados de exámenes, diagramas o notas de diseño.  
├── **`include/`**: Almacena las cabeceras públicas (`.h` o `.hpp`) que declaran las estructuras, funciones y clases.  
├── **`src/`**: Contiene el código fuente principal (`.cpp`) con la implementación lógica del examen.  
├── **`lib/`**: Destinado a bibliotecas externas de terceros o módulos estáticos locales necesarios para el proyecto.  
├── **`CMakeLists.txt`**: Script de configuración principal de **CMake** donde se definen las reglas de compilación, dependencias y objetivos.  
└── **`README.md`**: Este archivo, que sirve como guía de inicio rápido y documentación general del repositorio.  

