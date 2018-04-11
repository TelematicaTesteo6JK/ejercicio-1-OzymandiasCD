#include <iostream>

using namespace std;

/*
Funcion que calcula la cantidad a pagar por concepto de estacionamiento
    de 1 a 5 horas, la hora cuesta $10
    de 6 a 10 horas, la hora cuesta $9
    por mas de 10 horas el costo es de $7
*/
float pago_estacionamiento(int horas)
{
	int cant(0);
	if (horas>=0 && horas<=5)
		cant = horas*10;
	if (horas>=6 && horas<=10)
		cant = horas*9;
	if (horas>11)
		cant = horas*7;

	return cant;
}

#include <string>

#define TEST_BUFF_SIZE    8
#define FIELD_1_STR_SIZE  10
#define FIELD_2_STR_SIZE  15
#define FIELD_3_STR_SIZE  15
#define BLANK_SPACE       ' '

string get_formated_field(size_t field_str_size, int value)
{
	string str(field_str_size, BLANK_SPACE), str_value = to_string(value);
	str.replace(field_str_size / 2, str_value.size(), str_value);
	return str;
}

void print_test_table(int *test_data, int *test_expected_results, int *test_results, size_t length)
{
	if (test_data == nullptr || test_expected_results == nullptr || test_results == nullptr)
		return;

	cout << "TEST CASES" << endl;
	cout << "Test data | Expected data | Actual result | Pass/Fail " << endl;

	for (int i = 0; i < length; i++)
	{
		cout << get_formated_field(FIELD_1_STR_SIZE, test_data[i]) << "|";
		cout << get_formated_field(FIELD_2_STR_SIZE, test_expected_results[i]) << "|";
		cout << get_formated_field(FIELD_3_STR_SIZE, test_results[i]) << "|";
		cout << ((test_results[i] == test_expected_results[i]) ? "    Pass" : "    Fail") << endl;
	}
}

void casos_de_prueba()
{
	int test_data[TEST_BUFF_SIZE] = {3, 9, 15, 1, 5, 6, 10, 11};
	int test_expected_results[TEST_BUFF_SIZE] = {30, 81, 105, 10, 50, 54, 90, 77};
	int test_results[TEST_BUFF_SIZE];

	for (int i = 0; i < TEST_BUFF_SIZE; i++)
		test_results[i] = pago_estacionamiento(test_data[i]);
	
	print_test_table(test_data, test_expected_results, test_results, TEST_BUFF_SIZE);
}

int main()
{
    casos_de_prueba();
	return 0;
}
