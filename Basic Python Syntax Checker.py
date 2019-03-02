'''
Lab session 1 for 207SE
Tom Atkinson / SID:7694431
22 Jan 2019
'''

def getSyntax(inputSentence):
    #lists
    person = ['baxter', 'sheila', 'igor']
    action = ['recognise', 'eat', 'sees', 'pick']
    position = ['left', 'right', 'forwards', 'backwards']
    pronoun = ['I', 'you', 'him', 'her']
    thing = ['screwdriver', 'diamond', 'boat', 'ball', 'person', 'apple', 'dog']
    value = ['cheap', 'expensive', 'price-less']

    allList = person + action + position + pronoun + thing + value

    inputOrder = inputSentence.split(" ")
    syntaxSentence = ""
    
    #get the syntax of the sentence
    for word in inputOrder:
        if word in person:
            syntaxSentence = syntaxSentence + "person"
        if word in action:
            syntaxSentence = syntaxSentence + "action"
        if word in position:
            syntaxSentence = syntaxSentence + "position"
        if word in pronoun:
            syntaxSentence = syntaxSentence + "pronoun"
        if word in thing:
            syntaxSentence = syntaxSentence + "thing"
        if word in value:
            syntaxSentence = syntaxSentence + "value"
        if word not in allList:
            syntaxSentence = syntaxSentence + "unknown"
    return syntaxSentence

def confirmValid(syntaxSentence, inputSentence):
    acceptableSyntax = ["personactionthing", "personactionvaluething", "personactionposition", "pronounactionthing", "pronounactionposition"]
    #check if it's a valid sentence
    
    correct = False
    for item in acceptableSyntax:
        if syntaxSentence == item:
            correct = True

    if correct == True:
        print("The sentence has correct grammar: " + inputSentence)
    else:
        print("The sentence has incorrect grammar: " + inputSentence)

#Testing
if __name__ == "__main__":
    print("Some sentences may be falsely flagged as incorrect due to the restrictions on vocabulary and grammar rules.")
    testCases = ["baxter sees boat", "I pick diamond", "we eat apple", "eat ball", "sheila recognise cheap ball", "baxter baxter"]
    #for each case, run tests
    for test in testCases:
        confirmValid(getSyntax(test), test)


