#include <iostream>

int hitungPanjangString(const char str[]) {
    int panjang = 0;
    while (str[panjang] != '\0') {
        panjang++;
    }
    return panjang;
}

char keHurufBesar(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

int dapatkanNilaiAlfabet(char c) {
    char h = keHurufBesar(c);
    if (h >= 'A' && h <= 'Z') {
        return h - 'A' + 1;
    }
    return 0;
}

char konversiNilaiKeHuruf(int nilai) {
    return 'A' + (nilai - 1);
}

void enkripsiSandi(const char pesanAsli[], char pesanHasil[]) {
    int N = hitungPanjangString(pesanAsli);
    if (N == 0) {
        pesanHasil[0] = '\0';
        return;
    }

    pesanHasil[0] = keHurufBesar(pesanAsli[0]);

    for (int i = 1; i < N; i++) {
        char currentChar = keHurufBesar(pesanAsli[i]);
        char prevChar = keHurufBesar(pesanAsli[i - 1]);

        int nilaiCurrent = dapatkanNilaiAlfabet(currentChar);
        int nilaiPrev = dapatkanNilaiAlfabet(prevChar);

        if (nilaiCurrent == 0) {
            pesanHasil[i] = pesanAsli[i];
            continue;
        }

        int nilaiBaru = nilaiCurrent + nilaiPrev;

        if (nilaiBaru > 26) {
            nilaiBaru -= 26;
        }

        pesanHasil[i] = konversiNilaiKeHuruf(nilaiBaru);
    }

    pesanHasil[N] = '\0';
}

int main() {
    char pesanAsli[1000];
    char pesanTerenkripsi[1000];

    std::cout << "=== Problem 2: Alien-In-The-Middle ===\n";
    std::cout << "Masukkan pesan asli (tanpa spasi): ";
    std::cin >> pesanAsli;

    enkripsiSandi(pesanAsli, pesanTerenkripsi);

    std::cout << "Pesan terenkripsi: " << pesanTerenkripsi << "\n";

    return 0;
}
