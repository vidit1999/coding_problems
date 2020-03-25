#include <bits/stdc++.h>
using namespace std;

/*
Deoxyribonucleic acid, DNA is the primary information storage molecule in biological systems.
It is composed of four nucleic acid bases Guanine ('G'), Cytosine ('C'), Adenine ('A'), and Thymine ('T').

Ribonucleic acid, RNA, is the primary messenger molecule in cells.
RNA differs slightly from DNA its chemical structure and contains no Thymine.
In RNA Thymine is replaced by another nucleic acid Uracil ('U').

Create a function which translates a given DNA string into RNA.

For example:
DNAtoRNA("GCAT") returns ("GCAU")
The input string can be of arbitrary length - in particular,
it may be empty. All input is guaranteed to be valid,
i.e. each input string will only ever consist of 'G', 'C', 'A' and/or 'T'.

Tests
DNAtoRNA("TTTT")
DNAtoRNA("GCAT")
DNAtoRNA("GACCGCCGCC")
*/

// returns the rna of the corresponing given dna string
string DNAtoRNA(string dna){
	// Note that the dna string is not passed by reference
	// so although replace modifies the string inplace
	// it will not modify the dna string here
    replace(dna.begin(),dna.end(),'T','U');
    return dna;
}

// main function
int main(){
    string dna = "GACCGCCGCC";
    string rna = DNAtoRNA(dna);
    cout << rna << "\n" << dna << "\n";
    return 0;
}