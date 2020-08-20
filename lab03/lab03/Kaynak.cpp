#include <iostream>
using namespace std;
class CTable {
public:
    int* array;
    string  s_name;
    int iTableLength;
    CTable() {
        iTableLength = 8;
        s_name = "defaultName";
        array = new int[8];
        fillArray();
        cout << "without: " << s_name << endl;
    }


    CTable(string sName, int iTableLen) {
        s_name = sName;
        iTableLength = iTableLen;

        array = new int[iTableLen];
        fillArray();
        cout << "Parameter " << sName << endl;
    }


    CTable(const CTable& pcOther) {
        s_name = pcOther.s_name + "_copy";
        iTableLength = pcOther.iTableLength;
        array = new int[pcOther.iTableLength];
        fillArray();

        cout << "copy: " << s_name << endl;
    }

    void fillArray() {
        for (int i = 0; i < iTableLength; i++) {
            (array)[i] = i;
        }
    }


    ~CTable() {
        delete array;
        cout << "removing:  " << s_name << endl;
    }

    void vSetName(string sName) {
        s_name = sName;
    }

    bool bSetNewSize(int iTableLen) {
        if (iTableLen > 0) {

            iTableLength = iTableLen;
            array = new int[iTableLen];
            fillArray();
            return true;
        }
        else
        {

            return false;
        }


    }



    void  vPrint() {
        for (int i = 0; i < iTableLength; i++) {
            cout << (array)[i] << endl;
        }
    }

    CTable* pcClone() {
        CTable* cloneTable = new CTable(*this);
        return cloneTable;
    }


    void v_mod_tab(CTable* pcTab, int iNewSize) {
        if (iNewSize > 0) {
            pcTab->array = new int[iNewSize];
        }
        else
        {
            cout << "invalid table length" << endl;
        }

    }


    void v_mod_tab(CTable cTab, int iNewSize) {
        if (iNewSize > 0) {

            cTab.array = new int[iNewSize];
        }
        else
        {
            cout << "invalid table length" << endl;
        }

    }



    void vSetValueAt(int iOffset, int iNewVal) {
        if (iOffset > 0 && iOffset < iTableLength) {

            array[iOffset] = iNewVal;
        }
        else {
            cout << "invalid " << endl;
        }
    }




    void operator=(const CTable& table) {
        this->array = new int[table.iTableLength];
        this->iTableLength = table.iTableLength;

        for (int i = 0; i < this->iTableLength; i++) {
            this->array[i] = table.array[i];
        }
    }








};

int main() {
    CTable c_tab_0, c_tab_1;
    c_tab_0.bSetNewSize(6);
    c_tab_1.bSetNewSize(4);


    c_tab_1.vSetValueAt(2, 123);
    cout << "c_tab_0" << endl;
    c_tab_0.vPrint();
    cout << "c_tab_1 " << endl;

    c_tab_1.vPrint();
    cout << "\n" << endl;

    c_tab_0 = c_tab_1;
    //CTable c_tab_2;

    //c_tab_2 = c_tab_0 + c_tab_1;
    //cout<< " array of added values:  " << endl;
    //c_tab_2.vPrint();

    cout << "\n" << endl;

    return 0;
}


