<?php

$dbhost = 'localhost';	// //адрес хоста

$dbuser = 'u1056753';    // //Имя пользователя

$dbpass = 'r8C2G_vj';    // //пароль для подключения к Mysql

$dbname = 'u1056753_system';    // //имя базы данных

$client_ip = $_SERVER['REMOTE_ADDR'];

// получение значения переменных
    $id_device = $_GET["id_device"];
    $id_gas = $_GET["id_gas"];
    $ppm = $_GET["ppm"];


 
 $connect = mysql_connect($dbhost, $dbuser, $dbpass);//устанавливаем подключение к MySQL
  
if(! $connect )// проверяем состояние подключения
     {
die('Ошибка соединения: ' . mysql_error());
     }
else
{
echo 'Соединение установлено';

mysql_select_db ($dbname, $connect);// Выбираем базу данных

$sql = "INSERT INTO measures VALUES (NOW(), '$id_device', '$id_gas', '$ppm')";//Отправляем данные в таблицу
mysql_query($sql); 

if(!mysql_query($sql))
{echo 'Ошибка!';}
else
{echo 'Новая запись вставлена в базу';}

mysql_close($connect);// закрываем соединение с базой
}
?>