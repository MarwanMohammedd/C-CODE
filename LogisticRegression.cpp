#include <iostream>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

class LogisticRegression
{
private:
    const double Evalue = 2.71828;
    double bias = 0.0;
    double wieght1 = 0.0;
    double wieght2 = 0.0;
    double learning_rate;
    int iter;
    vector<double> error;
    double errorValue;

public:
    LogisticRegression(double learning_rate = 0.01, int iter = 50)
    {
        this->learning_rate = learning_rate;
        this->iter = iter;
    }
    vector<double> class1 = {2.7810836, 1.465489372, 3.396561688, 1.38807019, 3.06407232, 7.627531214, 5.332441248, 6.922596716, 8.675418651, 7.673756466};
    vector<double> class2 = {2.550537003, 2.362125076, 4.400293529, 1.850220317, 3.005305973, 2.759262235, 2.088626775, 1.77106367, 0.2420686549, 3.508563011};
    vector<double> y = {0, 1, 0, 1, 0, 1, 0, 0, 1, 1};

    double Sigmoid(double Evalue, double z)
    {
        return 1 / (1 + pow(Evalue, -z));
    }

    void Trainnig()
    {
        for (int i = 0; i < iter; i++)
        {
            int index = i % iter;
            double z = bias + wieght1 * class1[index] + wieght2 * class2[index];
            double prediction = Sigmoid(Evalue, -z);
            errorValue = y[index] - prediction;
            bias = bias - learning_rate * errorValue * prediction * (1 - prediction) * 1.0;
            wieght1 = wieght1 - learning_rate * errorValue * prediction * (1 - prediction) * class1[index];
            wieght2 = wieght2 - learning_rate * errorValue * prediction * (1 - prediction) * class2[index];
            cout << "bias=" << bias << " "
                 << "wieght1=" << wieght1 << " "
                 << "wieght2=" << wieght2 << " errorValue=" << errorValue << '\n';
            error.push_back(errorValue);
        }

        sort(error.begin(), error.end());
        cout << "Final Values are: "
             << "bias=" << bias << " "
             << "wieght1=" << wieght1 << " "
             << "wieght2=" << wieght2 << " error=" << error[0];
    }

    void Eval(double test1, double test2)
    {
        double prediction = bias + wieght1 * test1 + wieght2 * test2;
        cout << "\n\nThe value predicted by the model= " << prediction << '\n';
        prediction = prediction >= 0.5 ? 1 : 0;
        cout << "The class predicted by the model= " << prediction;
    }
};

int main()
{
    LogisticRegression l = LogisticRegression();
    l.Trainnig();
    l.Eval(7.673756466, 3.508563011);

    return 0;
}
