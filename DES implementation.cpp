#include <iostream>
//#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <string>
//#include <string.h>
//#include <iterator>
//#include <alg.h>
//#include<math.h>

//#include <bitset>
//#include <sstream>
//#include <assert.h>
//#include <stdlib.h>

#ifdef __GNUC__
#define __rdtsc __builtin_ia32_rdtsc
#else
#include <intrin.h>
#endif

using namespace std;

unsigned long long round_keys[16];

class Convert
{
public:
    Convert();
    ~Convert();
    string hexa_bin(std::string in);
    string bin_hex(std::string in);
private:
    std::map<char, std::string> hexa_bin_table;
    std::map<std::string, char> bin_hexa_table;


};

Convert::Convert()
{
    hexa_bin_table.insert(pair<char, std::string>('0', "0000"));
    hexa_bin_table.insert(pair<char, std::string>('1', "0001"));
    hexa_bin_table.insert(pair<char, std::string>('2', "0010"));
    hexa_bin_table.insert(pair<char, std::string>('3', "0011"));
    hexa_bin_table.insert(pair<char, std::string>('4', "0100"));
    hexa_bin_table.insert(pair<char, std::string>('5', "0101"));
    hexa_bin_table.insert(pair<char, std::string>('6', "0110"));
    hexa_bin_table.insert(pair<char, std::string>('7', "0111"));
    hexa_bin_table.insert(pair<char, std::string>('8', "1000"));
    hexa_bin_table.insert(pair<char, std::string>('9', "1001"));
    hexa_bin_table.insert(pair<char, std::string>('A', "1010"));
    hexa_bin_table.insert(pair<char, std::string>('B', "1011"));
    hexa_bin_table.insert(pair<char, std::string>('C', "1100"));
    hexa_bin_table.insert(pair<char, std::string>('D', "1101"));
    hexa_bin_table.insert(pair<char, std::string>('E', "1110"));
    hexa_bin_table.insert(pair<char, std::string>('F', "1111"));
    bin_hexa_table.insert(pair<std::string, char>("0000", '0'));
    bin_hexa_table.insert(pair<std::string, char>("0001", '1'));
    bin_hexa_table.insert(pair<std::string, char>("0010", '2'));
    bin_hexa_table.insert(pair<std::string, char>("0011", '3'));
    bin_hexa_table.insert(pair<std::string, char>("0100", '4'));
    bin_hexa_table.insert(pair<std::string, char>("0101", '5'));
    bin_hexa_table.insert(pair<std::string, char>("0110", '6'));
    bin_hexa_table.insert(pair<std::string, char>("0111", '7'));
    bin_hexa_table.insert(pair<std::string, char>("1000", '8'));
    bin_hexa_table.insert(pair<std::string, char>("1001", '9'));
    bin_hexa_table.insert(pair<std::string, char>("1010", 'A'));
    bin_hexa_table.insert(pair<std::string, char>("1011", 'B'));
    bin_hexa_table.insert(pair<std::string, char>("1100", 'C'));
    bin_hexa_table.insert(pair<std::string, char>("1101", 'D'));
    bin_hexa_table.insert(pair<std::string, char>("1110", 'E'));
    bin_hexa_table.insert(pair<std::string, char>("1111", 'F'));


}

Convert::~Convert()
{
}

string Convert::hexa_bin(std::string in)
{
    string binary_out = "";
    for (int i = 0; i < in.size(); i++) {
        binary_out += hexa_bin_table[in[i]];
    }
    return binary_out;
}

string Convert::bin_hex(std::string in)
{
    // binary to hexa conver

    string hexa = "";
    for (int i = 0; i < in.length(); i += 4) {
        string hex_digit = "";
        hex_digit += in[i];
        hex_digit += in[i + 1];
        hex_digit += in[i + 2];
        hex_digit += in[i + 3];
        hexa += bin_hexa_table[hex_digit];
    }
    return hexa;

}


class Mathmatics
{
public:
    Mathmatics();
    ~Mathmatics();
    std::string genral_permutaion(std::string in, int n, int* table);
    unsigned long long genral_permutaion(unsigned long long in, int n, int* table,int N);
    std::string circular_shift_left(string in, int N_shifts);
    std::string xor_op(std::string in1, std::string in2);
    std::string s_box_op(std::string in);

    unsigned long circular_shift_left(unsigned long in, unsigned long N_shifts);
    // wlahi ma3rf mofti 3amelha
    void swap(unsigned long long &a, unsigned long long& b);
    unsigned long long xor_op(unsigned long long in1, unsigned long long in2);
    unsigned long s_box_op(unsigned long long in);

    int initial_permutation_table[64] = { 58, 50, 42, 34, 26, 18, 10, 2,
                             60, 52, 44, 36, 28, 20, 12, 4,
                             62, 54, 46, 38, 30, 22, 14, 6,
                             64, 56, 48, 40, 32, 24, 16, 8,
                             57, 49, 41, 33, 25, 17, 9, 1,
                             59, 51, 43, 35, 27, 19, 11, 3,
                             61, 53, 45, 37, 29, 21, 13, 5,
                             63, 55, 47, 39, 31, 23, 15, 7 };

    int s_box_table[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                          0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                          4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                          15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
                        { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                          3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                          0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                          13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },

                        { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                          13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                          13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                          1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
                        { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                          13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                          10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                          3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
                        { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                          14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                          4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                          11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
                        { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                          10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                          9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                          4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
                        { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                          13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                          1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                          6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
                        { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                          1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                          7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                          2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };

    int expansion_table[48] = { 32, 1, 2, 3, 4, 5, 4, 5,6, 7, 8, 9, 8, 9, 10, 11,12, 13, 12, 13, 14, 15, 16, 17,16, 17, 18, 19, 20, 21, 20, 21,22, 23, 24, 25, 24, 25, 26, 27,28, 29, 28, 29, 30, 31, 32, 1 };

    int per[32] = { 16, 7, 20, 21,
                    29, 12, 28, 17,
                    1, 15, 23, 26,
                    5, 18, 31, 10,
                    2, 8, 24, 14,
                    32, 27, 3, 9,
                    19, 13, 30, 6,
                    22, 11, 4, 25 };

    int final_perm[64] = { 40, 8, 48, 16, 56, 24, 64, 32,
                           39, 7, 47, 15, 55, 23, 63, 31,
                           38, 6, 46, 14, 54, 22, 62, 30,
                           37, 5, 45, 13, 53, 21, 61, 29,
                           36, 4, 44, 12, 52, 20, 60, 28,
                           35, 3, 43, 11, 51, 19, 59, 27,
                           34, 2, 42, 10, 50, 18, 58, 26,
                           33, 1, 41, 9, 49, 17, 57, 25 };

    int keyp[56] = { 57, 49, 41, 33, 25, 17, 9,
                 1, 58, 50, 42, 34, 26, 18,
                 10, 2, 59, 51, 43, 35, 27,
                 19, 11, 3, 60, 52, 44, 36,
                 63, 55, 47, 39, 31, 23, 15,
                 7, 62, 54, 46, 38, 30, 22,
                 14, 6, 61, 53, 45, 37, 29,
                 21, 13, 5, 28, 20, 12, 4 };

    int shift_table[16] = { 1, 1, 2, 2,
                            2, 2, 2, 2,
                            1, 2, 2, 2,
                            2, 2, 2, 1 };

    int key_comp[48] = { 14, 17, 11, 24, 1, 5,
                         3, 28, 15, 6, 21, 10,
                         23, 19, 12, 4, 26, 8,
                         16, 7, 27, 20, 13, 2,
                         41, 52, 31, 37, 47, 55,
                         30, 40, 51, 45, 33, 48,
                         44, 49, 39, 56, 34, 53,
                         46, 42, 50, 36, 29, 32 };
};

Mathmatics::Mathmatics()
{}
Mathmatics::~Mathmatics()
{
}
unsigned long long Mathmatics::genral_permutaion(unsigned long long in, int n, int* table, int N)
{
    unsigned long long out = 0;
    for (int i = 0; i < n; i++)
        out |= (in >> (N - table[n - i - 1]) & 1) << i;
    return out;
}
std::string Mathmatics::genral_permutaion(std::string in, int n, int* table)
{

    string permuation_out = "";
    for (int i = 0; i < n; i++) {
        permuation_out += in[table[i] - 1];
    }
    return permuation_out;

}
std::string Mathmatics::circular_shift_left(string in, int N_shifts)
{
    string shifted_out = "";
    for (int i = 0; i < N_shifts; i++) {
        for (int j = 1; j < 28; j++) {
            shifted_out += in[j];
        }
        shifted_out += in[0];
        in = shifted_out;
        shifted_out = "";
    }
    return in;
}
std::string Mathmatics::xor_op(std::string in1, std::string in2)
{
    string out = "";
    int i = 0;
    while (i < in1.size())
    {
        (in1[i] != in2[i]) ? out += "1" : out += "0";
        i++;
    }
    return out;
}
std::string Mathmatics::s_box_op(std::string in)
{
    std::string out = "";
    for (int i = 0; i < 8; i++) {
        int row = 2 * int(in[i * 6] - '0') + int(in[i * 6 + 5] - '0');
        int col = 8 * int(in[i * 6 + 1] - '0') + 4 * int(in[i * 6 + 2] - '0') + 2 * int(in[i * 6 + 3] - '0') + int(in[i * 6 + 4] - '0');
        int val = s_box_table[i][row][col];
        out += char(val / 8 + '0');
        val = val % 8;
        out += char(val / 4 + '0');
        val = val % 4;
        out += char(val / 2 + '0');
        val = val % 2;
        out += char(val + '0');
    }
    return out;
}

unsigned long Mathmatics::circular_shift_left(unsigned long in, unsigned long N_shifts)
{
    return ((in << N_shifts)| (in >> (28- N_shifts)) ) & 0x0FFFFFFF;
}

void Mathmatics::swap(unsigned long long &a, unsigned long long& b)
{
    unsigned long long temp = a;
    a = b;
    b = temp;
    return;
}

unsigned long long Mathmatics::xor_op(unsigned long long in1, unsigned long long in2)
{
    return unsigned long long(in1 ^ in2);
}

unsigned long  Mathmatics::s_box_op(unsigned long long in)
{
    unsigned long long bits,box_out;
    unsigned long long out=0;

    for (int i = 0; i < 8; i++)
    {
        // 6 bits
        bits = (in & (0xFC0000000000 >> (i * 6))) >> ((7 - i) * 6);

        unsigned long row = ((bits & 0x21) >> 4) | ((bits & 0x21) & 1);
        unsigned long col = (bits & 0x1E) >> 1;

        box_out = s_box_table[i][row][col];
        // hnaka
        //out <<= 4;
        out = out << 4;
        out |= box_out;

    }

    return out;
}



class EncrptionDES
{
public:
    EncrptionDES();
    ~EncrptionDES();

    std::string encrypt(string pt, vector<string> rkb, vector<string> rk);
    unsigned long long encrypt(unsigned long long pt);
    unsigned long long read(const char* text);
    void key_generation(unsigned long long key);

private:

};

EncrptionDES::EncrptionDES()
{
    //Convert Convert;
    //Mathmatics Math;
}

EncrptionDES::~EncrptionDES()
{
}
std::string EncrptionDES::encrypt(string pt, vector<string> rkb, vector<string> rk)
{
    Convert Conv;
    Mathmatics Math;

    pt = Conv.hexa_bin(pt);// text

    pt = Math.genral_permutaion(pt, 64, Math.initial_permutation_table);

    string left = pt.substr(0, 32);
    string right = pt.substr(32, 32);

    for (int i = 0; i < 16; i++) {

        string right_expanded = Math.genral_permutaion(right, 48, Math.expansion_table);

        string x = Math.xor_op(rkb[i], right_expanded);

        string op = Math.s_box_op(x);

        op = Math.genral_permutaion(op, 32, Math.per);

        x = Math.xor_op(op, left);

        left = x;

        if (i != 15) {
            swap(left, right);
        }
    }
    string combine = left + right;

    string cipher = Conv.bin_hex(Math.genral_permutaion(combine, 64, Math.final_perm));
    return cipher;
}

unsigned long long EncrptionDES::encrypt(unsigned long long pt)
{
    // the text is already in bit format
    Mathmatics Math;

    pt = Math.genral_permutaion(pt, 64, Math.initial_permutation_table, 64);

    unsigned long long left = unsigned long long((pt >> 32) & 0xFFFFFFFF);
    unsigned long long right = unsigned long long((pt) & 0xFFFFFFFF);

    for (int i = 0; i < 16; i++)
    {
        unsigned long long right_expanded = Math.genral_permutaion(right, 48, Math.expansion_table, 32);

        unsigned long long xor_res = Math.xor_op(right_expanded, round_keys[i]);

        unsigned long op = Math.s_box_op(xor_res);

        op = Math.genral_permutaion(op, 32, Math.per, 32);

        xor_res = Math.xor_op(op, left);

        left = xor_res;

        if (i != 15) {
            Math.swap(left, right);
        }

    }

    unsigned long long combined = unsigned long long((left << 32) | right);
    unsigned long long cipher = Math.genral_permutaion(combined, 64, Math.final_perm,64);


    return cipher;
}

unsigned long long EncrptionDES::read(const char* datain)
{
    unsigned long long out = 0;
    char c = datain[0];
    for (int i = 0; i < 16; i++)
    {
        c = datain[i];
        if (c >= '0' && c <= '9')
            out |= (unsigned long long)(c - '0') << ((15 - i) << 2);
        else if (c >= 'A' && c <= 'F')
            out |= (unsigned long long)(c - 'A' + 10) << ((15 - i) << 2);
        else if (c >= 'a' && c <= 'f')
            out |= (unsigned long long)(c - 'a' + 10) << ((15 - i) << 2);
    }
    return out;
}

void EncrptionDES::key_generation(unsigned long long key)
{
    Mathmatics Math;
    unsigned long long per = 0;
    per = Math.genral_permutaion(key, 56, Math.keyp, 64);


    unsigned long left_key = unsigned long ((per >> 28) & 0x0FFFFFFF);
    unsigned long right_key = unsigned long ((per) & 0x0FFFFFFF);

    for (int i = 0; i < 16; i++)
    {
        if (i == 0 || i == 1 || i == 8 || i == 15)
        {
            left_key = Math.circular_shift_left(left_key, 1);
            right_key = Math.circular_shift_left(right_key, 1);
        }
        else
        {
            left_key = Math.circular_shift_left(left_key, 2);
            right_key = Math.circular_shift_left(right_key, 2);
        }

        unsigned long long combined = unsigned long long(unsigned long long(left_key )<< 28 | unsigned long long(right_key));
        
        unsigned long long final_key = Math.genral_permutaion(combined, 48, Math.key_comp, 56);


        round_keys[i] = final_key;

    }
}

vector<string>  rev_vectors(vector<string> v) {

 
        vector<string>  re;
        // Iterate over a vector in backward direction using
        // indexing


        for (int i = 0; i < v.size(); i++)
            re.push_back(v[v.size() - 1 - i]);        
        return re;

}

void reverseKeys()
{

    unsigned long long  temp[16];
    for (int i = 0; i < 16; i++)
        temp[i] = round_keys[15 - i];

    for (int i = 0; i < 16; i++)
        round_keys[i] = temp[i];

}


int main(int argc, char** argv)
{
    for (int i = 0; i < 16; i++)
    {
        round_keys[i] = 0;
    }
   //Convert Conv;
   //Mathmatics Math;
   
   //std::string text = "7DB033DD14D6F975";
   //std::string key = "1323445A6D788381";
   
   /*
   std::string operation = argv[1];
   std::string text = argv[2];
   std::string key = argv[3];
   */


    //std::string text_hexa = Conv.hexa_bin(text);
    /*
    std::string key_hexa = Conv.hexa_bin(key);


    key_hexa = Math.genral_permutaion(key_hexa, 56, Math.keyp); // key without parity
    //cout << endl << key << endl;


    string left = key_hexa.substr(0, 28);
    string right = key_hexa.substr(28, 28);

    vector<string> rkb; // rkb for RoundKeys in binary
    vector<string> rk; // rk for RoundKeys in hexadecimal

    for (int i = 0; i < 16; i++) {
        left = Math.circular_shift_left(left, Math.shift_table[i]);
        right = Math.circular_shift_left(right, Math.shift_table[i]);

        string combine = left + right;

        string RoundKey = Math.genral_permutaion(combine, 48, Math.key_comp);

        rkb.push_back(RoundKey);
        rk.push_back(Conv.bin_hex(RoundKey));
    }
    */
    /*for (size_t i = 0; i < rkb.size(); i++)
    {
        cout << rkb[i];
    }
    cout << "\n";*/


    EncrptionDES EN;
    std::string operation = argv[1];
    unsigned long long text = EN.read(argv[2]);
    unsigned long long key = EN.read(argv[3]);/*
    std::string operation = "encrypt";
    unsigned long long text = EN.read("7DB033DD14D6F975");
    unsigned long long key = EN.read("1323445A6D788381");*/
    EN.key_generation(key);

    std::string out = "cipher: ";
    if (operation == "decrypt")
    {
        reverseKeys();
        //rkb = rev_vectors(rkb);
        //rk = rev_vectors(rk);
        //std::reverse(rkb.begin(), rkb.end());
        //std::reverse(rk.begin(), rk.end());
        out = "plain: ";
    }
    //std::cout << text << endl;
    long long t1 = __rdtsc();
    unsigned long long cipher = EN.encrypt(text);
    long long t2 = __rdtsc();

    //std::string operation_out = EN.encrypt(text_hexa, rkb, rk);
    //std::string operation_out = EN.encrypt(text, rkb, rk);
    //out += operation_out;
    std::cout << out << hex<< uppercase << cipher;
    printf("\nCycles: %lld\n", t2 - t1);
    return 0;
}
