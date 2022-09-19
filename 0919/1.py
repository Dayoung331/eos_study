import random

Num1 = random.randrange(1,101)
Num2 = random.randrange(1,101)
yunsan = random.choice('+-x%')
count = 0


while True :
  print(f'{Num1} {yunsan} {Num2} :')
  delnum = input("숫자 입력(종료 누르면 종료) :")


  if delnum == "종료":
    print(f'맞춘 개수 {count}개')
    break

  elif delnum != "종료":
    Num1 = int(Num1)
    Num2 = int(Num2)

    if yunsan == "+":
      jungdab = int(Num1 + Num2)
  
      if delnum == jungdab:
        count += 1
  
      else:
        print("오답입니다.")



    elif yunsan == "-":
      jungdab = int(Num1 - Num2)
      if delnum == jungdab:
        count += 1
      else:
        print("오답입니다.")


    elif yunsan == "x":
      jungdab = int(Num1*Num2)
      if delnum == jungdab:
        count += 1
      else:
        print("오답입니다.")

    elif yunsan == "%":
      jungdab == int(Num1/Num2)