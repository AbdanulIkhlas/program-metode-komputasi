# Program untuk menyelesaikan SPL dengan metode Gauss-Seidel

def gauss_seidel(coeff_matrix, constants, initial_guess, max_iterations, tolerance):
    n = len(constants)  # Jumlah variabel
    x = initial_guess[:]  # Nilai awal
    for iteration in range(1, max_iterations + 1):
        x_new = x[:]
        for i in range(n):
            # Hitung nilai baru untuk variabel i
            sum1 = sum(coeff_matrix[i][j] * x_new[j] for j in range(n) if j != i)
            x_new[i] = (constants[i] - sum1) / coeff_matrix[i][i]
        
        # Tampilkan hasil iterasi
        print(f"Iterasi {iteration}: {['{:.4f}'.format(val) for val in x_new]}")

        # Cek konvergensi
        if all(abs(x_new[i] - x[i]) < tolerance for i in range(n)):
            print("Konvergensi tercapai.")
            break
        
        x = x_new[:]  # Perbarui nilai untuk iterasi berikutnya
    
    return x

# Input interaktif
print("\n\nProgram Metode Gauss-Seidel untuk SPL")
print("\n----------------------------------------------------------")
print("Contoh Input (Pastikan Matriks Diagonal Dominan)")
print("Baris 1 : 3 -0.1 -0.2")
print("Baris 2 : 0.1 7 -0.3")
print("Baris 3 : 0.3 -0.2 10")
print("Masukkan konstanta (elemen dipisahkan spasi): 7.85 -19.3 71.4")
print("Masukkan tebakan awal (elemen dipisahkan spasi): 0 0 0")
print("Masukkan jumlah iterasi maksimum: 10 (atau sesuai soal maks 3 juga boleh, hasil sama)")
print("Masukkan toleransi (contoh: 0.0001): 0.0001")
print("Contoh ini sudah sesuai soal SPL Gauss Seidel, jadi bisa di ikuti saja")
print("----------------------------------------------------------\n\n")
print("Masukkan matriks koefisien (baris per baris, elemen dipisahkan spasi):")
coeff_matrix = []
for i in range(3):
    coeff_matrix.append(list(map(float, input(f"Baris {i+1}: ").split())))
constants = list(map(float, input("Masukkan konstanta (elemen dipisahkan spasi): ").split()))
initial_guess = list(map(float, input("Masukkan tebakan awal (elemen dipisahkan spasi): ").split()))
max_iterations = int(input("Masukkan jumlah iterasi maksimum: "))
tolerance = float(input("Masukkan toleransi (contoh: 0.0001): "))

# Jalankan metode Gauss-Seidel
solution = gauss_seidel(coeff_matrix, constants, initial_guess, max_iterations, tolerance)
print(f"Solusi akhir: {['{:.4f}'.format(val) for val in solution]}")