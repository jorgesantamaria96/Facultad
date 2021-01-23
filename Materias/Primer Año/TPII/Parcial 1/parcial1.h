/* IFDEF */

typedef struct Indocumentado{
    char *nombre;
    char *domicilio;
    int edad;
    int cant_anios;
}Ind;

Ind *crear_Indocumentado(char *nombre, char *domicilio, int edad, int cant_anios);

void mostrar_Indocumentado(Ind *persona);

void agregar_Indocumentados(Ind **lista_personas, Ind *persona, int cant_personas);

void mostrar_lista_Indocumentado(Ind **lista_personas, int cant_personas);

void buscar_Indocumentados(Ind **lista_personas,int cant_personas, int anios_residencia);

/* ENDIF*/
