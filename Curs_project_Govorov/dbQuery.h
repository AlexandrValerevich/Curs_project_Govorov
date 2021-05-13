#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;
using namespace System;
using namespace System::Data::OleDb;
using namespace System::Windows::Forms;

/*Возвращает строку подключения*/
String^ StringConnection();

/*Возвращает строку с id искмой строки*/
String^ SelectID(
	OleDbConnection^ dbConnection, 
	String^ SELECT_ID, 
	String^ FROM, 
	String^ WHERE);
/*Возвращает ссылку на строки которые возвращены из таблицы*/
OleDbDataReader^ SelectRow(
	OleDbConnection^ dbConnection,
	String^ SELECT,
	String^ FROM,
	String^ WHERE = nullptr,
	String^ ORDER_BY = nullptr,
	String^ GROUP_BY = nullptr,
	String^ HAVING = nullptr);
/*Возвращает true если запрос выполнен успешно*/
bool InsertRow(
	OleDbConnection^ dbConnection,
	String^ TABLE,
	String^ COLUMN,
	String^ VALUES);
/*Возвращает true если запрос выполнен успешно*/
bool InsertRow(
	OleDbConnection^ dbConnection,
	String^ TABLE,
	Array^  COLUMN,
	Array^ VALUES);
/*Возвращает true если строка успешно обновлена*/
bool UpdateRow(
	OleDbConnection^ dbConnection,
	String^ TABLE,
	String^ SET,
	String^ WHERE);
/*Возвращает true если строка успешно удалена*/
bool DeleteRow(
	OleDbConnection^ dbConnection,
	String^ FROM,
	String^ WHERE);

