#ifndef __PROTOCOL_H
#define __PROTOCOL_H

//Caracteres especiales
#define START_FRAME_CHAR 0xCF
#define STOP_FRAME_CHAR 0xDF
#define ESCAPE_CHAR 0xEF
#define STUFFING_MASK 0x02

//Definiciones generales
#define INT32U unsigned int
#define INT16U unsigned short
#define INT8U unsigned char

#define CHEKSUM_TYPE INT16U
#define COMMAND_TYPE INT8U

#define CHECKSUM_SIZE (sizeof(CHEKSUM_TYPE))
#define COMMAND_SIZE (sizeof(COMMAND_TYPE))
#define START_SIZE (1)
#define END_SIZE (1)

#define MINIMUN_FRAME_SIZE (START_SIZE+COMMAND_SIZE+CHECKSUM_SIZE+END_SIZE)

#define MAX_DATA_SIZE (32)
#define MAX_FRAME_SIZE (2*(MAX_DATA_SIZE))


//Macros para obtener campos
#define NetToU32(array,posicion) ((((INT32U)array[posicion+3])<<24)|(((INT32U)array[posicion+2])<<16)|(((INT32U)array[posicion+1])<<8)|((INT32U)array[posicion]))
#define NetToU16(array,posicion) ((((INT16U)array[posicion+1])<<8)|(((INT16U)array[posicion])))
#define NetToU8(array,posicion) ((INT8U)array[posicion]

#define SwapBytes16(datos) ((0xFF&(((unsigned short)datos)>>8))|((((unsigned short)datos)&0xFF)<<8))


//Códigos de los comandos


typedef enum {
    COMANDO_NO_IMPLEMENTADO,
    COMANDO_DATO,
    COMANDO_SENSOR


} commandTypes;

//Codigos de Error
#define PROT_ERROR_BAD_CHECKSUM (-1)
#define PROT_ERROR_RX_FRAME_TOO_LONG (-2)
#define PROT_ERROR_NOMEM (-3)
#define PROT_ERROR_STUFFED_FRAME_TOO_LONG (-4)
#define PROT_ERROR_COMMAND_TOO_LONG (-5)

//Estructuras relacionadas con los parámetros

#pragma pack(1)	//Con esto consigo que el alineamiento de las estructuras en memoria del PC (32 bits) sea igual que el del microcontrolador (16 bits)...

#define PACKED 

		 
typedef struct {
	unsigned char command;
} PACKED PARAM_COMANDO_NO_IMPLEMENTADO;

typedef struct{
    unsigned int peticion;
    float dato;
}PACKED PARAM_COMANDO_DATO;

typedef struct{
    unsigned int peticion;
        char sensor;
    unsigned int datoint;
}PACKED PARAM_COMANDO_SENSOR;



#pragma pack()	//...Pero solo para los comandos que voy a intercambiar, no para el resto.

//Macros que obtienen campos del paquete
#define decode_command_type(paquete,offset) (NetToU8(paquete,(offset)))
#define extract_packet_command_param(paquete,payload,campo) memcpy(campo,paquete+COMMAND_SIZE,payload);

//Otra macro que puede ser de utilidad
#define check_command_param_size(frame_size,param_size) (!(frame_size-param_size-COMMAND_SIZE-CHECKSUM_SIZE))
#define get_param_size(frame_size) (frame_size-COMMAND_SIZE-CHECKSUM_SIZE)

//Funciones de la libreria
int create_frame(unsigned char *frame, unsigned char command_type, void * param, int param_size, int max_size);
int destuff_and_check_checksum (unsigned char *frame, int max_size);


// La funcionalidad de estas dos en la parte de PC (QTs) las hace el componente QtSerialPort, con 'write' y 'readAll'
//int send_frame(int COM, unsigned char *frame, int FrameSize);
//int receive_frame(int COM, unsigned char *frame, int maxFrameSize);


#endif
