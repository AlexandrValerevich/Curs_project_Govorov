#include "dbQuery.h"

String^ StringConnection()
{
	return "provider=Microsoft.ACE.OLEDB.12.0;Data Source=University.accdb";
}

String^ SelectID(
	OleDbConnection^ dbConnection,
	String^ SELECT_ID,
	String^ FROM,
	String^ WHERE)
{
	if (String::IsNullOrEmpty(SELECT_ID)) {
		MessageBox::Show("Неверно заданы параметры функции");
		return "";
	}

	if (String::IsNullOrEmpty(FROM)) {
		MessageBox::Show("Неверно заданы параметры функции");
		return "";
	}

	if (String::IsNullOrEmpty(WHERE)) {
		MessageBox::Show("Неверно заданы параметры функции");
		return "";
	}

	String^ id;

	String^ query = "SELECT TOP 1 " + SELECT_ID + " FROM " + FROM + " WHERE " + WHERE + " ;";
	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection); //Выполнение команды

	auto dbReaderID = dbCommand->ExecuteReader();

	if (!dbReaderID->HasRows)
		return nullptr;

	dbReaderID->Read();
	id = dbReaderID[0]->ToString();

	return id;
}

OleDbDataReader^ SelectRow(
	OleDbConnection^ dbConnection,
	String^ SELECT,
	String^ FROM,
	String^ WHERE,
	String^ ORDER_BY,
	String^ GROUP_BY,
	String^ HAVING )	
{

	if (String::IsNullOrEmpty(SELECT)) {
		MessageBox::Show("Неверно заданы параметры функции");
		return nullptr;
	}

	if (String::IsNullOrEmpty(FROM)) {
		MessageBox::Show("Неверно заданы параметры функции");
		return nullptr;
	}

	String^ query = "SELECT " + SELECT + " FROM " + FROM; //начало запроса
	
	if (!String::IsNullOrEmpty(WHERE))
		query += " WHERE " + WHERE;

	if (!String::IsNullOrEmpty(GROUP_BY)) {
		query += " GROUP BY " + GROUP_BY;
		if (!String::IsNullOrEmpty(HAVING)) {
			query += " HAVING " + HAVING;
		}
	}
	
	if (!String::IsNullOrEmpty(ORDER_BY))
		query += " ORDER BY " + ORDER_BY;
	
	query += " ;"; //конец запроса

	OleDbCommand^ dbCommand = gcnew OleDbCommand(query, dbConnection); //Создание команды
	return dbCommand->ExecuteReader(); //Выполнение команды
}

bool InsertRow(
	OleDbConnection^ dbConnection,
	String^ TABLE,
	String^ COLUMN,
	String^ VALUES)
{
	String^ query = "INSERT INTO " + TABLE + " ( " + COLUMN + " ) " + " VALUES ( " + VALUES + " );";
	auto dbCommand = gcnew OleDbCommand(query, dbConnection);

	try
	{
		if (dbCommand->ExecuteNonQuery() == 1) {
			return true;
		}
		return false;
	}
	catch (const std::exception& ex)
	{
		string message = ex.what();
		String^ Message = "";
		for (auto it : message) {
			Message += it;
		}
		MessageBox::Show(Message, "Внимание!");
	}

	return false;

}

bool InsertRow(
	OleDbConnection^ dbConnection,
	String^ TABLE,
	Array^ COLUMN,
	Array^ VALUES)
{
	String^ query = "INSERT INTO " + TABLE + " ( ";

	for each (String^ col in COLUMN)
	{
		query += col + ", ";
	}

	int indexComma = query->LastIndexOf(',');
	query->Remove(indexComma);
	query += " ) VALUES ( ";

	for each (String ^ val in VALUES)
	{
		query += val + ", ";
	}

	indexComma = query->LastIndexOf(',');
	query->Remove(indexComma);
	query += " );";

	auto dbCommand = gcnew OleDbCommand(query, dbConnection);

	if (dbCommand->ExecuteNonQuery() == 1) {
		return true;
	}
	return false;
}

bool UpdateRow(
	OleDbConnection^ dbConnection,
	String^ TABLE,
	String^ SET,
	String^ WHERE)
{
	String^ query = "UPDATE " + TABLE + " SET " + SET + " WHERE " + WHERE + " ;";
	auto dbCommand = gcnew OleDbCommand(query, dbConnection);

	if (dbCommand->ExecuteNonQuery() == 1) {
		return true;
	}
	return false;
}

bool DeleteRow(
	OleDbConnection^ dbConnection,
	String^ FROM,
	String^ WHERE)
{
	String^ query = "DELETE FROM " + FROM +  " WHERE " + WHERE + " ;";
	auto dbCommand = gcnew OleDbCommand(query, dbConnection);

	if (dbCommand->ExecuteNonQuery() == 1) {
		return true;
	}
	return false;
}


