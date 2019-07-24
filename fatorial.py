def fatorial(num):
    if num == 1:
        return 1
    else:
        return num * fatorial(num - 1)

if __name__ == '__main__':
    a = input("Digite um número: ")
    print(f'O fatorial de {a} é {fatorial(int(a))}')