<?php

$dbhost = 'localhost';	// //����� �����

$dbuser = 'u1056753';    // //��� ������������

$dbpass = 'r8C2G_vj';    // //������ ��� ����������� � Mysql

$dbname = 'u1056753_system';    // //��� ���� ������

$client_ip = $_SERVER['REMOTE_ADDR'];

// ��������� �������� ����������
    $id_device = $_GET["id_device"];
    $id_gas = $_GET["id_gas"];
    $ppm = $_GET["ppm"];


 
 $connect = mysql_connect($dbhost, $dbuser, $dbpass);//������������� ����������� � MySQL
  
if(! $connect )// ��������� ��������� �����������
     {
die('������ ����������: ' . mysql_error());
     }
else
{
echo '���������� �����������';

mysql_select_db ($dbname, $connect);// �������� ���� ������

$sql = "INSERT INTO measures VALUES (NOW(), '$id_device', '$id_gas', '$ppm')";//���������� ������ � �������
mysql_query($sql); 

if(!mysql_query($sql))
{echo '������!';}
else
{echo '����� ������ ��������� � ����';}

mysql_close($connect);// ��������� ���������� � �����
}
?>