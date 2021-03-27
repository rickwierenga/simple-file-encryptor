// Shift each bit of the file by the sum of bits of the password :)

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void encrypt(ifstream &file, string filename, string password);
void decrypt(ifstream &file, string filename, string password);

int main() {
  // Get filename from user. Check if a file with that name exists.
  string line;
  string filename;
  cout << "Select file: ";
  cin >> filename;
  ifstream file;
  file.open(filename, ios::in);
  if (!file.is_open()) {
    cout << "File does not exist!" << "\n";
    return 1;
  }

  // Get password from user.
  string password;
  cout << "Password: ";
  cin >> password;

  // Ask operation
  string op;
  cout << "Opereation (encrypt/decrypt): ";
  cin >> op;

  if (op == "encrypt") {
    encrypt(file, filename, password);
  } else if (op == "decrypt") {
    decrypt(file, filename, password);
  } else {
    cout << "Invalid command\n";
    return 2;
  }

  file.close();
  cout << "Goodbye!\n";
}

int computeSum(string str) {
  int sum;
  for (char &c : str) {
    sum += int(c);
  }
  return sum;
}

void encrypt(ifstream &file, string filename, string password) {
  // Create new output file.
  ofstream toFile;
  toFile.open("encrypt-" + filename, ios::out);
  string line;

  // Compute password value
  int sum = computeSum(password);

  // "encrypt"
  if (file.is_open()) {
    while (getline(file, line)) {
      cout << line << "\n";
      for (char &c : line) {
        toFile << char(int(c) + sum);
      }
      toFile << std::endl;
    }
    file.close();
    toFile.close();
  } else {
    cout << "File does not exist!" << "\n";
    return;
  }

  return;
}

void decrypt(ifstream &file, string filename, string password) {
  // Create new output file.
  ofstream toFile;
  toFile.open("decrypted-" + filename, ios::out);
  string line;

  // Compute password value
  int sum = computeSum(password);

  // decrypt
  if (file.is_open()) {
    cout << "\n" << "Selected: " << filename << "\n";
    while (getline(file, line)) {
      for (char &c : line) {
        toFile << char(int(c) - sum);
      }
      toFile << std::endl;
    }
    file.close();
    toFile.close();
  } else {
    cout << "File does not exist!" << "\n";
    return;
  }

  return;
}

