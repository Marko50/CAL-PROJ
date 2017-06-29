all: FeupCal

FeupCal: main.cpp Agencia.cpp Alojamento.cpp Cidade.cpp connection.cpp Data.cpp Epoca.cpp graphviewer.cpp Hora.cpp matcher.cpp Menu.cpp Quarto.cpp Viagem.cpp
	g++ main.cpp Agencia.cpp Alojamento.cpp Cidade.cpp connection.cpp Data.cpp Epoca.cpp graphviewer.cpp Hora.cpp matcher.cpp Menu.cpp Quarto.cpp Viagem.cpp -Wall

