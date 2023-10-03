#include <iostream>
#include <map>
#include <string>
using namespace std;

  map<string, string> codon_map{
  {"UUU", "Phenylalanine"},
  {"UUC", "Phenylalanine"},
  {"UUA", "Leucine"},
  {"UUG", "Leucine"},
  {"UCU", "Serine"},
  {"UCC", "Serine"},
  {"UCA", "Serine"},
  {"UCG", "Serine"},
  {"UAU", "Tyrosine"},
  {"UAC", "Tyrosine"},
  {"UAA", "Stop"},
  {"UAG", "Stop"},
  {"UGU", "Cysteine"},
  {"UGC", "Cysteine"},
  {"UGA", "Stop"},
  {"UGG", "Tryptophan"},
  {"CUU", "Leucine"},
  {"CUC", "Leucine"},
  {"CUA", "Leucine"},
  {"CUG", "Leucine"},
  {"CCU", "Proline"},
  {"CCC", "Proline"},
  {"CCA", "Proline"},
  {"CCG", "Proline"},
  {"CAU", "Histidine"},
  {"CAC", "Histidine"},
  {"CAA", "Glutamine"},
  {"CAG", "Glutamine"},
  {"CGU", "Arginine"},
  {"CGC", "Arginine"},
  {"CGA", "Arginine"},
  {"CGG", "Arginine"},
  {"AUU", "Isoleucine"},
  {"AUC", "Isoleucine"},
  {"AUA", "Isoleucine"},
  {"AUG", "Methionine"},
  {"ACU", "Threonine"},
  {"ACC", "Threonine"},
  {"ACA", "Threonine"},
  {"ACG", "Threonine"},
  {"AAU", "Asparagine"},
  {"AAC", "Asparagine"},
  {"AAA", "Lysine"},
  {"AAG", "Lysine"},
  {"AGU", "Serine"},
  {"AGC", "Serine"},
  {"AGA", "Arginine"},
  {"AGG", "Arginine"},
  {"GUU", "Valine"},
  {"GUC", "Valine"},
  {"GUA", "Valine"},
  {"GUG", "Valine"},
  {"GCU", "Alanine"},
  {"GCC", "Alanine"},
  {"GCA", "Alanine"},
  {"GCG", "Alanine"},
  {"GAU", "Aspartic acid"},
  {"GAC", "Aspartic acid"},
  {"GAA", "Glutamic acid"},
  {"GAG", "Glutamic acid"},
  {"GGU", "Glycine"},
  {"GGC", "Glycine"},
  {"GGA", "Glycine"},
  {"GGG", "Glycine"},
  };

string transcription(string inputStrand, int direction)
{
    string rna;
    string transcribedStrand;
    for (int i = 0; i < inputStrand.size(); i++)
    {
      if (inputStrand[i] == 'A')
      {
        rna += 'U';
        transcribedStrand+='T';
      }
      if (inputStrand[i] == 'T')
      {
        rna+= 'A';
        transcribedStrand+='A';
      }
      if (inputStrand[i] == 'C')
      {
        rna+='G';
        transcribedStrand+='G';
      }
      if (inputStrand[i] == 'G')
      {
        rna+='C';
        transcribedStrand+='C';
      }
    }

    // if the direction is 5' to 3'
    if (direction == 2) {
    for (int i = 0; i < inputStrand.size(); i++)
    {
      if (transcribedStrand[i] == 'A')
      {
        rna+='U';
      }
      if (transcribedStrand[i] == 'T')
      {
        rna+='A';
      }
      if (transcribedStrand[i] == 'C')
      {
        rna+='G';
      }
      if (transcribedStrand[i] == 'G')
      {
        rna+='C';
      }
    }
    }
    if (direction == 1)
    {
    cout << "nontemplate strand: " << transcribedStrand;
    cout << endl;
    cout << "template strand: " << inputStrand << endl;
    cout << "mRNA strand: " << rna;
    cout << endl;
    }
    if (direction == 2)
    {
    cout << "nontemplate strand: " << inputStrand << endl;
    cout << "template strand: " << transcribedStrand;
    cout << endl;
    cout << "mRNA strand: " << rna;
    cout << endl;
    }

    return rna;

}

string validString(string strand)
{
  if (strand.size() % 3 != 0) 
  {
    cout << "Invalid Strand: Not divisible by 3" << endl;
    return "invalid";
  }
  for (int i = 0; i < strand.size(); i++)
  {
    if (
      strand[i] == 'A' or
      strand[i] == 'T' or 
      strand[i] == 'G' or 
      strand[i] == 'C'
    )
    return "valid";
  }
  cout << "Invalid Strand: Contains an invalid nucleotide" << endl;
  return "invalid";
}

void translation(string mRNA)
{
  for (int i = 0; i < mRNA.size(); i+=3)
  {
    cout << mRNA.substr(i, 3) << ": " << codon_map[mRNA.substr(i, 3)] << endl;
  }
}

int main()
{   
    int direction; 
    string strand;
    string mRNA;
    cout << "Enter the direction of the DNA strand: " << endl;
    cout << "(1) 3' to 5' or (2) 5' to 3'" << endl;
    cin >> direction;
    cin.ignore(10000, '\n');
    cout << "Enter the DNA strand: ";
    getline(cin, strand);
    if (validString(strand) == "invalid")
      return 0;
    mRNA = transcription(strand, direction);
    translation(mRNA);
}