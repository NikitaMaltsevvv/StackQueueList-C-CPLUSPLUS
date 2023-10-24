#include"List.h"
#include"Stek.h"
#include"Queue.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Список: " << endl;
	try
	{
		List ls;
		ls.push(1);
		ls.push(1);
		ls.push(5);
		ls.push(4);
		ls.push(1);
		ls.Print();
		cout << "popx3" << endl;
		cout << ls.pop(1) << endl;
		cout << ls.pop(3) << endl;
		ls.Print();
		cout << "Удаление одинаковых элементов." << endl;
		ls.Del_odin_el();
		ls.Print();
		cout << ls.pop(100);
	}
	catch (const char *ex)
	{
		cout << "Ошибка в списке!" << ex << endl;
	}
	
	cout << "\nСтек: " << endl;
	try
	{
		Stek st(5);
		st.Print();
		cout << "popx3 " << endl;
		cout << st.pop() << endl;
		cout << st.pop() << endl;
		cout << st.pop() << endl;
		st.Print();
	}
	catch (const char* ex)
	{
		cout << "Ошибка в стеке!" << ex << endl;
	}
	

	cout << "\nОчередь: " << endl;
	try
	{
		Queue qu(3);
		qu.push(56);
		qu.push(43);
		qu.Print();
		cout << "popx3 " << endl;
		cout << qu.pop() << endl;
		cout << qu.pop() << endl;
		cout << qu.pop() << endl;
		qu.Print();
	}
	catch (const char* ex)
	{
		cout << "Ошибка в очереди!" << ex << endl;
	}
	
	system("pause");
	return 0;
}