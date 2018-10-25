def translate(phrase):
	words = 0
	point = 0
	newString = ""
	for char in phrase:
		if char == ' ':
			words+=1

	counter = 0
	while counter <= words:
		counter +=1
		newWord, point = getWord(phrase,point)
		newString = newString + newWord + ' '
	return newString


def getWord(phrase,point):
	counter = 0
	while phrase[point + counter:point + counter+1] != ' ' and counter < len(phrase):
		counter+=1
	word = phrase[point:point + counter] #Here is the word
	point = point + counter+1

	firstVowel = True
	while isNotVowel(word[0:1]):
		word = word[1:]+word[0:1]
		firstVowel = False

	if firstVowel:
		word = word + "yay"
	else:
		word = word + "ay"


	return word, point


def isNotVowel(letter):
	if letter == 'A' or letter == 'I' or letter == 'E'or letter == 'O' or letter == 'U' or letter == 'Y':
		return False
	if letter == 'a' or letter == 'i' or letter == 'e' or letter == 'o' or letter == 'u' or letter == 'y':
		return False
	else:
		return True