Parte A 

Buscar información acerca estructura del directorio ​ /proc​ , y averiguar los siguientes datos, teniendo en cuenta la versión de kernel que está corriendo: 

1. Tipo y modelo de CPU. 
2. Versión del kernel. 
3. Tiempo en días, horas, minutos y segundos que han transcurrido desde que se inició el sistema operativo. 
4. Cuánto tiempo de CPU ha sido empleado para procesos de usuario, de sistema y cuando tiempo no se usó. 
5. Cuánta memoria tiene y cuánta está disponible. 
6. Cuántos sistemas de archivo soporta el kernel 
7. Cuántos pedidos de lectura/escritura a disco se han realizado. 
8. Cuántos cambios de contexto han sucedido. 
9. Cuántos procesos se crearon desde que inició el sistema. 

INFO:
http://www.linuxtotal.com.mx/index.php?cont=info_admon_016

http://www.tldp.org/pub/Linux/docs/ldp-archived/system-admin-guide/translations/es/html/ch04s07.html



/proc/uptime: Un archivo pequeño que solo tiene dos números: por cuantos segundos tu sistema ha estado encendido, y cuantos segundos ha estado inactivo.


>> cat /proc/cpuinfo (1)
>> cat /proc/version (2)
>> cat /proc/uptime (3)
>> cat /proc/stat (4)
>> cat /proc/meminfo (5)
>> cat /proc/filesystems (6) 
>> cat /proc/diskstats (7)		info: https://listas.usla.org.ar/pipermail/lugna/2006-September/004523.html
>> cat /proc/stat (8)
>> cat /proc/stat (9) 

practico 1: 
 -Capitulo 7 advanced linux programming
