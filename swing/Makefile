JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = MainFrame.java Client.java

default: classes

run: classes
	java Client

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class
