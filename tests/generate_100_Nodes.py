def generate100NodeTest():
    with open('Test_300_Node.c', 'w') as writeFile:
        # Include files
        writeFile.write('#include <stdio.h>' + '\n')
        writeFile.write('#include "salmalloc.h"' + '\n\n\n')

        # function to test        
        testList = '\n\
ssize_t testList() \n\
{\n\
 		sNode *temp = copy_list(4);\n\
		ssize_t count = 0;\n\
       		while(temp != NULL) {\n\
       			ssize_t *compare = temp->memSegment + sizeof(smem_blk_seg);\n\
			if (*compare != count) {\n\
				printf("Test failed at count %zd when compare was %zd.\\n", count, *compare);\n\
       				return FALSE;\n\
       			}\n\
       			temp = (sNode*)temp->next;\n\
        		count++;\n\
       		}\n\
       		return TRUE;\n\
}\n\n\n\n'

        writeFile.write(testList)


        testSkipNodes = '\n\
ssize_t testSkipNodes()\n\
{\n\
        size_t i = 0;\n\
        sNode *temp = copy_list(4);\n\
        while (temp != NULL) {\n\
        	int ch = temp->numNodesAhead;\n\
	        printf("i == %zu and ch: %zd.\\n", i, ch);\n\
		temp = temp->skipNodes.fwd_hundredSpecialNode;\n\
        	i++;\n\
        }\n\
        return TRUE;\n\
}\n\n\n'

        writeFile.writelines(testSkipNodes)

        # main defined
        writeFile.write('int main()' + '\n' + '{' + '\n')

        maxCount = 203
        # declare variables
        for i in range(0, maxCount):
            if i is 0:
                writeFile.write('\tssize_t *a' + str(i) + ',')
            elif i != maxCount - 1:
                writeFile.write(' *a' + str(i) + ',')
            elif i == maxCount - 1:
                writeFile.write(' *a' + str(i) + ';')
                writeFile.write('\n\n\n')


        # give memory to variables
        for i in range(0, maxCount):
            writeFile.write('\ta' + str(i) + ' = ' + ' (ssize_t *) salmalloc(sizeof(ssize_t));' + '\n')
            writeFile.write('\t*a' + str(i) + ' = ' + str(i) + ';' + '\n')
            writeFile.write('\n')

        # Test now
        writeFile.write('\tif (testList() != TRUE) {\n')
        writeFile.write('\t\treturn FALSE;\n\t}\n\n')
    

        # close bracket and end
        writeFile.write('\tprintf("Test was successful.\\n");\n\n')
        writeFile.write('\ttestSkipNodes();\n\n')
        writeFile.write('\treturn TRUE;\n\n')

        writeFile.write('}' + '\n\n\n')



def demo(flagCreate100Node = True):
    if flagCreate100Node is True:
        generate100NodeTest()
    



if __name__ == '__main__':
    demo(flagCreate100Node = True)
