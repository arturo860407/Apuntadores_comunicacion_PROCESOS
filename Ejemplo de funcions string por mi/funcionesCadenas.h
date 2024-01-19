

/**
	Conjuntos de funciones para cadenas ejemplos
**/

// longitud de una cadena (sin el '\0') 
unsigned cadlen(const char* caract)
{
    unsigned i=0;
    while (caract[i] != '\0')
        i++;
    return i;
}

// copia de una cadena carac2 en otra carac1
char* cadcpy(char* carac1, const char* carac2)
{
    int i=0;
    while ((carac1[i]=carac2[i]) != '\0') 
        i++;
    return carac1;
}

// añadir carac2 a continuación de carac1 (sin el '\0')
char* cadcat(char* carac1, const char* carac2)
{
    int i=0, j=0;
    while (carac1[i] != '\0') 
        i++;
    while (carac2[j] != '\0') 
        carac1[i++] = carac2[j++];
    carac1[i] = '\0';
    return carac1 ;
}

// comparar alfabéticamente dos cadenas de caracteres
int cadcmp(char* carac1, char* carac2)
{ 
    int i = 0, dif;
    while (carac1[i] != '\0') {
        dif = carac1[i] - carac2[i]; 
        if (dif == 0)
            i++;
        else 
            return (dif);
    }
    if (carac2[i] == '\0')
        return(0);
    return (carac1[i] - carac2[i]);
} 



/* este filtro convierte todas las letras a
   minúsculas*/
char filtro(char c)
{
   
    if(c>='A' && c<='Z')
        return (c+'a'-'A');
  
    return c;
}

/* este filtro convierte todas las acentuadas a letras 
   minúsculas*/
char filtroAcentuadas(char c)
{
   
   //Á o á
    if(c==-127||c==-95)
	return 97;
   // É o é
    if(c==-119||c==-87)
	return 101;
   // Í o í
    if(c==-115||c==-83)
	return 105;
   // Ó o ó
    if(c==-109||c==-77)
	return 111;
   // Ú o ú
    if(c==-102||c==-70)
	return 117;
    
    return c;
}

/*
  Busca las letras acentuadas de un string 
*/
char *acentuadas(char* carac1)
{ 
    int i = 0, j=0;
    char *aux=NULL;
    aux=(char *)malloc(sizeof(char)*cadlen(carac1));
    while (carac1[i] != '\0') {
          if(carac1[i] ==-61)
		aux[j]=(filtroAcentuadas(carac1[++i]));
         else
	     aux[j]=carac1[i];
        i++;j++;
			
    }
    return aux;
} 


/* Esta función compara cadenas considerando idénticas
   mayúsculas y minúsculas, vocales acentuadas y sin acentuar*/
int cadcompmayusculas(char* carac1, char* carac2)
{ 
    int i = 0, dif;
    carac1=acentuadas(carac1);
    carac2=acentuadas(carac2);
    while (filtro(carac1[i]) != '\0') {
	
	dif = filtro(carac1[i]) - filtro(carac2[i]); 
        if (dif == 0)
            i++;
        else 
            return (dif);
    }
    if (filtro(carac2[i]) == '\0')
        return(0);
    return (filtro(carac1[i]) - filtro(carac2[i]));
} 
