# Program untuk Interpolasi Lagrange

def lagrange_interpolation(x_values, y_values, x_target):
    n = len(x_values)
    result = 0.0
    for i in range(n):
        # Hitung basis polinomial L_i(x)
        L_i = 1.0
        for j in range(n):
            if j != i:
                L_i *= (x_target - x_values[j]) / (x_values[i] - x_values[j])
        result += L_i * y_values[i]  # Tambahkan ke hasil
    return result

# Input interaktif
print("\n\nProgram Interpolasi Lagrange")
print("\n----------------------------------------------------------")
print("Contoh Input (Contoh ini sudah sesuai soal SPL Gauss Seidel, jadi bisa di ikuti saja)")
print("Masukkan jumlah data: 4")
print("Masukkan nilai x_i dan f(x_i):")
print("Data 1 (x_i f(x_i)): 0.2 1.2")
print("Data 2 (x_i f(x_i)): 0.4 1.1")
print("Data 3 (x_i f(x_i)): 0.6 0.8")
print("Data 4 (x_i f(x_i)): 0.8 0.9")
print("Masukkan nilai x yang ingin dihitung (dipisahkan spasi): 0.3 0.5 0.7")
print("----------------------------------------------------------\n\n")

n = int(input("Masukkan jumlah data: "))
x_values = []
y_values = []
print("Masukkan nilai x_i dan f(x_i):")
for i in range(n):
    x, y = map(float, input(f"Data {i+1} (x_i f(x_i)): ").split())
    x_values.append(x)
    y_values.append(y)

x_targets = list(map(float, input("Masukkan nilai x yang ingin dihitung (dipisahkan spasi): ").split()))

# Hitung nilai interpolasi untuk setiap x_target
for x_target in x_targets:
    result = lagrange_interpolation(x_values, y_values, x_target)
    print(f"f({x_target}) = {result:.4f}")