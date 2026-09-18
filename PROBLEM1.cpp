#include <iostream>

void simulasiEliminasi(int N, int K) {
    int astronot[1000];
    
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }
    
    int sisaAstronot = N;
    int indeksAwal = 0;
    
    std::cout << "Urutan astronot yang dieliminasi:\n";
    
    while (sisaAstronot > 1) {
        int targetIndeks = (indeksAwal + K - 1) % sisaAstronot;
        int tereliminasi = astronot[targetIndeks];
        std::cout << tereliminasi << " ";
        
        if (tereliminasi % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }
        
        if (K < 2) {
            K = 2;
        }
        
        for (int i = targetIndeks; i < sisaAstronot - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        
        sisaAstronot--;
        indeksAwal = targetIndeks;
    }
    
    std::cout << "\n\nAstronot terakhir yang bertahan: " << astronot[0] << "\n";
}

int main() {
    int N, K;
    
    std::cout << "=== Problem 1: The Last Astronaut ===\n";
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> N;
    std::cout << "Masukkan nilai hitungan awal (K): ";
    std::cin >> K;
    
    if (N <= 0 || K <= 0) {
        std::cout << "Input harus berupa bilangan bulat positif.\n";
        return 0;
    }
    
    std::cout << "\n";
    simulasiEliminasi(N, K);
    
    return 0;
}
