#include <iostream>
#include <fstream>


using namespace std;



class HomeAccounting {

public:
    int other = 0;

    void recordExpense()
    {
        long  int expenditure;
        cout << "vvedite trati: ";
        cin >> expenditure;
        this->other = expenditure;
        ofstream fout("expenses.txt", ios::app);

        if (fout.is_open())
        {
            fout << expenditure << endl;
            fout.close();
        }
        else
        {
            cout << "Unable to open file!" << "\n";
        }
    }
    void recordIncome()
    {
        long int summ;
        cout << "vvedite summ: ";
        cin >> summ;

        ofstream fout("incomes.txt", ios::app);

        if (fout.is_open())
        {
            fout << summ << endl;
            fout.close();
        }
        else
        {
            cout << "Unable to open file!" << "\n";
        }
    }

    int calculateBalance()
    {
        long int incomes = 0;
        long int expenes = 0;


        ifstream fin("incomes.txt");

        if (fin.is_open())
        {
            int token;

            while (fin >> token)
            {
                incomes += token;

            }
            fin.close();
        }
        else
        {
            cout << "Unable to open file!" << "\n";
        }

        ifstream fen("expenses.txt");

        if (fen.is_open())
        {
            int token;
            while (fen >> token)
            {
                expenes += token;
            }
            fen.close();
        }
        else
        {
            cout << "Unable to open file!" << "\n";
        }
        cout << "balance" << "\t";
        cout << incomes - expenes << "\n";

        return expenes;
    }
    void percentmonth() {


        int sumfood, sumcloths, sumelectronic, sumperevod;
        int oct = this->other;

        cout << this->other << " trati za month " << "\n";
        while (true) {
            cout << "sumfood ";
            cin >> sumfood;
            if (sumfood >= 0 and sumfood <= oct) {
                oct -= sumfood;
                break;
            }

        }

        while (true) {
            cout << "sumcloths ";
            cin >> sumcloths;
            if (sumcloths >= 0 and sumcloths <= oct) {
                oct -= sumcloths;
                break;
            }
        }

        while (true) {
            cout << "sumelectronic ";
            cin >> sumelectronic;
            if (sumelectronic >= 0 and sumelectronic <= oct) {
                oct -= sumelectronic;
                break;
            }
        }

        while (true) {
            cout << "sumperevod ";
            cin >> sumperevod;
            if (sumperevod >= 0 and sumperevod <= oct) {
                oct -= sumperevod;
                break;
            }
        }

        cout << "persent month " << "\n";
        cout << sumfood * 100 / this->other << "% food" << "\t";
        cout << sumcloths * 100 / this->other << "% cloths " << "\t";
        cout << sumelectronic * 100 / this->other << "% electronic " << "\t";
        cout << sumperevod * 100 / this->other << "% perevod " << "\t";
        cout << oct * 100 / this->other << "% other expense" << "\n";


    }
    void percentall() {
        int expenes;
        expenes = calculateBalance();
        int sumfood, sumcloths, sumelectronic, sumperevod;
        int oct = expenes;

        cout << expenes << " vse trati " << "\n";
        while (true) {
            cout << "sumfood ";
            cin >> sumfood;
            if (sumfood >= 0 and sumfood <= oct) {
                oct -= sumfood;
                break;
            }

        }

        while (true) {
            cout << "sumcloths ";
            cin >> sumcloths;
            if (sumcloths >= 0 and sumcloths <= oct) {
                oct -= sumcloths;
                break;
            }
        }

        while (true) {
            cout << "sumelectronic ";
            cin >> sumelectronic;
            if (sumelectronic >= 0 and sumelectronic <= oct) {
                oct -= sumelectronic;
                break;
            }
        }

        while (true) {
            cout << "sumperevod ";
            cin >> sumperevod;
            if (sumperevod >= 0 and sumperevod <= oct) {
                oct -= sumperevod;
                break;
            }
        }

        cout << "persent month " << "\n";
        cout << sumfood * 100 / expenes << "% food" << "\t";
        cout << sumcloths * 100 / expenes << "% cloths " << "\t";
        cout << sumelectronic * 100 / expenes << "% electronic " << "\t";
        cout << sumperevod * 100 / expenes << "% perevod " << "\t";
        cout << oct * 100 / expenes << "% other expense" << "\n";


    }

};
int main() {
    HomeAccounting* user1 = new HomeAccounting();
    user1->recordExpense();
    user1->recordIncome();
    user1->percentall();
    user1->percentmonth();
}
