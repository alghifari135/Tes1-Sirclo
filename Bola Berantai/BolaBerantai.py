def main():
	# Deklarasi Variabel
	stokBola1 = []
	stokBola2 = [0 for i in range(30)]
	perintah = []

	# Pembacaan Input
	file_name = input('Masukkan nama file (bola.txt) : ')
	files = open(file_name, 'r')
	file_line_list = files.readlines()
	
	# String Bola
	rantaiBola1 = file_line_list[0].split()
	rantaiBola2 = ''.join(rantaiBola1)

	# Jumlah ketersediaam bola
	stokBola1 = (file_line_list[1].replace(':',' ').replace(',',' ').split())
	for i in range(0,len(stokBola1),2):
		stokBola2[ord(stokBola1[i])-65]=int(stokBola1[i+1])

	# Perintah Selip/Ambil
	for i in range(0,len(file_line_list)-2):
		perintah.append(file_line_list[i+2].split())

	# Menjalankan perintah
	for i in range(0, len(perintah)):
		if (len(perintah[i])>1):
			if (perintah[i][0]=="SELIP" and stokBola2[ord(perintah[i][1])-65]>0 and int(perintah[i][2])<=len(rantaiBola2) and int(perintah[i][2])>=0):
				rantaiBola2 = rantaiBola2[:int(perintah[i][2])] + perintah[i][1] + rantaiBola2[int(perintah[i][2]):]
				stokBola2[ord(perintah[i][1])-65]-=1
			elif (perintah[i][0]=="AMBIL" and int(perintah[i][1])<len(rantaiBola2) and int(perintah[i][1])>=0):
				stokBola2[ord(rantaiBola2[int(perintah[i][1])])-65]+=1
				rantaiBola2 = rantaiBola2[:int(perintah[i][1])] + rantaiBola2[int(perintah[i][1])+1:]

	# Output Hasil
	print(rantaiBola2)
	first = False
	for i in range(26):
		if (stokBola2[i]>0):
			if (first==True):
				print(',',end='')
			first=True
			print(chr(i+65),end=':')
			print(stokBola2[i], end='')

	print()

if __name__ == '__main__':
    main()