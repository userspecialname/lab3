// UI.cpp

#include "UI.h"
#include <iostream>
#include <limits>
#include "Vector.h"
#include "Complex.h"
#include "tests.h"

using namespace std;

template <typename T>
void input_vector(Vector<T>& vec) {
    cout << "������ ࠧ��� �����: ";
    int size;
    cin >> size;

    // ������� ���� ����� ⮣� �� ⨯�, �� � �室��� �����, �� � ���� ࠧ��஬
    // �ᯮ��㥬 ࠧ��� 1 ��� ��।������ ⨯�, ��⥬ ������� ࠧ���
    Vector<T> new_vec(vec.get_size() > 0 ? 1 : 2, 1);
    new_vec = Vector<T>(new_vec.get_size() > 0 ? 1 : 2, size);

    cout << "������ " << size << " ����⮢ ��� �����:" << endl;
    for (int i = 0; i < size; ++i) {
        T element;
        cin >> element;
        new_vec.set(i, element);
    }

    // ��ᢠ����� ���� ����� �室���� ������
    vec = new_vec;
}

void display_UI() {
    cout << "1. Create vectors" << endl;
    cout << "2. Perform operations" << endl;
    cout << "3. Run tests" << endl;
    cout << "0. Exit" << endl;
}

void your_choice() {
    int choice;
    bool valid_input = false;
    int data_type = 0;
    int vector_type = 0;
    Vector<int>* vec_int1 = nullptr;
    Vector<int>* vec_int2 = nullptr;
    Vector<double>* vec_double1 = nullptr;
    Vector<double>* vec_double2 = nullptr;
    Vector<Complex>* vec_complex1 = nullptr;
    Vector<Complex>* vec_complex2 = nullptr;

    while (!valid_input) {
        display_UI();
        cout << "������ ��� �롮�: ";

        if (cin >> choice) {
            switch (choice) {
                case 0:
                    cout << "��室 �� �ணࠬ��." << endl;
                    exit(0);
                case 1: {
                    cout << "�롥�� ⨯ ������:" << endl;
                    cout << "1. int" << endl;
                    cout << "2. double" << endl;
                    cout << "3. Complex" << endl;
                    cin >> data_type;
                    if (data_type < 1 || data_type > 3) {
                        cout << "������ �롮� ⨯� ������." << endl;
                        break;
                    }

                    cout << "�롥�� ⨯ ����� (1 - ArraySequence, 2 - ListSequence): ";
                    cin >> vector_type;
                    if (vector_type != 1 && vector_type != 2) {
                        cout << "������ �롮� ⨯� �����." << endl;
                        break;
                    }

                    // ������� ������ � ᮮ⢥��⢨� � ��࠭�� ⨯�� ������
                    switch (data_type) {
                        case 1:
                            vec_int1 = new Vector<int>(vector_type);
                            vec_int2 = new Vector<int>(vector_type);
                            input_vector(*vec_int1);
                            input_vector(*vec_int2);
                            break;
                        case 2:
                            vec_double1 = new Vector<double>(vector_type);
                            vec_double2 = new Vector<double>(vector_type);
                            input_vector(*vec_double1);
                            input_vector(*vec_double2);
                            break;
                        case 3:
                            vec_complex1 = new Vector<Complex>(vector_type);
                            vec_complex2 = new Vector<Complex>(vector_type);
                            input_vector(*vec_complex1);
                            input_vector(*vec_complex2);
                            break;
                    }
                    cout << "������ �ᯥ譮 ᮧ����." << endl;
                    break;
                }
                case 2: {
                    if (data_type == 0) {
                        cout << "���砫� �롥�� ⨯ ������ (�㭪� 1)." << endl;
                        break;
                    }

                    cout << "�롥�� ������:" << endl;
                    cout << "1. �������� ����஢" << endl;
                    cout << "2. ��������� ����� �� ᪠���" << endl;
                    cout << "3. �����୮� �ந�������� ����஢" << endl;
                    int operation;
                    cin >> operation;

                    switch (operation) {
                        case 1: {
                            cout << "������� ᫮����� ����஢: ";
                            switch (data_type) {
                                case 1: print((*vec_int1 + *vec_int2)); break;
                                case 2: print(*vec_double1 + *vec_double2); break;
                                case 3: print(*vec_complex1 + *vec_complex2); break;
                            }
                            break;
                        }
                        case 2: {
                            double scalar;
                            cout << "������ ᪠���: ";
                            cin >> scalar;
                            cout << "������� 㬭������ �� ᪠���: ";
                            switch (data_type) {
                                case 1: print(*vec_int1 * scalar); break;
                                case 2: print(*vec_double1 * scalar); break;
                                case 3: print(*vec_complex1 * scalar); break;
                            }
                            break;
                        }
                        case 3: {
                            cout << "�����୮� �ந�������� ����஢: ";
                            switch (data_type) {
                                case 1: cout << vec_int1->dot(*vec_int2) << endl; break;
                                case 2: cout << vec_double1->dot(*vec_double2) << endl; break;
                                case 3: cout << vec_complex1->dot(*vec_complex2) << endl; break;
                            }
                            break;
                        }
                        default:
                            cout << "������ �롮� ����樨." << endl;
                    }
                    break;
                }
                case 3:
                    cout << "����� ��⮢..." << endl;
                    runAllTests();
                    cout << "����� �����襭�." << endl;
                    break;
                default:
                    cout << "������ �롮�. ��������, �롥�� 0, 1, 2 ��� 3." << endl;
                    break;
            }
        } else {
            cout << "�����४�� ����. ��������, ������ �᫮." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // �᢮������� ������
    delete vec_int1;
    delete vec_int2;
    delete vec_double1;
    delete vec_double2;
    delete vec_complex1;
    delete vec_complex2;
}