#!/bin/bash -
#title       :20100210_Jogo_da_velha.sh
#description :This is tic tac toe game
#author      :André Augusto Tissot
#date        :20100210
#version     :9.05
#usage       :bash 20100210_Jogo_da_velha.sh
jogador=()
jogador_da_vez='X'
tabuleiro=(- - - - - - - - -)

introducao(){
clear
echo -e "\n\n"
echo "  DDDDDDDDD DDDDDDD DDDDDDD   DDDDD     DDDDDD     DDDDD"
echo "       DD   DD   DD DD     D DD   DD    DD   DD   DD   DD"
echo "       DD   DD   DD DD       D     D    DD    DD  DD   DD"
echo "       DD   DD   DD DD  DDDD D     D    DD    DD  DDDDDDD"
echo "  D   DD    DD   DD DD    DD DD   DD    DD   DD   DD   DD"
echo "   DDDD     DDDDDDD DDDDDDD   DDDDD     DDDDDD    DD   DD"
echo
echo "  DD      DD DDDDDDD DD     DD   DD  DDDDD      #   #"
echo "  DD      DD DD      DD     DD   DD DD   DD  ###########"
echo "   DD    DD  DDDDDD  DD     DDDDDDD DDDDDDD     #   #"
echo "    DD  DD   DD      DD     DD   DD DD   DD  ###########"
echo "     DDDD    DDDDDDD DDDDDD DD   DD DD   DD     #   #"
avance_introducao
echo "        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
echo "        %                                         %"
echo "        %         SCRIPT DESENVOLVIDO POR         %"
echo "        %                                         %"
echo "        %           ANDRÉ AUGUSTO TISSOT          %"
echo "        %                                         %"
echo "        %                                         %"
echo "        %          andrehtissot@gmail.com         %"
echo "        %                                         %"
echo "        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
avance_introducao
definicao_jogadores
}

avance_introducao(){
sleep 3
clear
echo -e "\n\n\n"
}

definir_jogador(){
echo -n -e "    Digite o nome do Jogador $(($1+1))\n    "
read jogador[$1]
while [ ${#jogador[$1]} -eq 0 ]; do
  echo "Digite o nome do Jogador $(($1+1))"
  read jogador[$1]
done
}

definicao_jogadores(){
jogador=()
definir_jogador 0
definir_jogador 1
clear
echo -e -n "\n\n    "
if [ ${jogador[0]} == ${jogador[1]} ]; then
  echo 'Jogadores com o mesmo nome!'
  sleep 1
  definicao_jogadores
else
  echo "Bem-vindos(as), ${jogador[0]} e ${jogador[1]}"
  sleep 1
  clear
  principal
fi
}

verificar_sequencia(){
  if [ ${tabuleiro[${1}]} != '-' ] && [ ${tabuleiro[${1}]} = ${tabuleiro[${2}]} ] && [ ${tabuleiro[${2}]} = ${tabuleiro[${3}]} ]; then
    fim_do_jogo
  fi
}

verificar_termino(){
  verificar_sequencia 0 1 2
  verificar_sequencia 3 4 5
  verificar_sequencia 6 7 8
  verificar_sequencia 0 1 2
  verificar_sequencia 6 3 0
  verificar_sequencia 0 1 2
  verificar_sequencia 7 4 1
  verificar_sequencia 8 5 2
  verificar_sequencia 0 1 2
  verificar_sequencia 6 4 2
  verificar_sequencia 8 4 0
if [ `localizar_o_ultimo_espaco_nao_preenchido` -eq 0 ]; then
  velha
fi
}

localizar_o_ultimo_espaco_nao_preenchido(){
contador=$((${#tabuleiro[@]}-1))
until [ ${tabuleiro[${contador}]} = - ] || [ $contador -eq 0 ]; do
  contador=$(($contador-1))
done
echo $contador
}

mostrar_celula(){
if [ ${tabuleiro[${1}]} = "-" ]; then
  echo -n '         '
elif [ ${tabuleiro[${1}]} = "X" ]; then
  case $2 in
    1)echo -n ' \\   // ';;
  	2)echo -n '  \\ //  ';;
  	3)echo -n '   |X|   ';;
  	4)echo -n '  // \\  ';;
  	5)echo -n ' //   \\ ';;
	esac
else
  case $2 in
    1)echo -n '  OOOOO  ';;
  	2)echo -n ' OO   OO ';;
  	3)echo -n ' OO   OO ';;
  	4)echo -n ' OO   OO ';;
  	5)echo -n '  OOOOO  ';;
	esac
fi
}

fim_do_jogo(){
if [ $jogador_da_vez = 'X' ]; then
  jogador_vencedor=${jogador[1]}
else
  jogador_vencedor=${jogador[0]}
fi
jogador_vencedor=${jogador_vencedor[0]:0:17}
for i in `seq 1 $(($((17-${#jogador_vencedor}))/2))`; do
   jogador_vencedor='%'$jogador_vencedor
   jogador_vencedor=$jogador_vencedor'%'
done
if [ $((${#jogador_vencedor}%2)) = 1 ]; then
  jogador_vencedor=$jogador_vencedor'%'
fi
novamente=''
until [ ${#novamente} = 1 ] && [ $novamente == 's' -o $novamente == 'n' ]; do
  clear
  echo -e "\n\n\n\n"
  echo '    @@@@@@@@@@@@@@@@@@@@@@@@@@@@'
  echo '    @@                        @@'
  echo '    @@        Parabéns!       @@'
  echo "    @@   ${jogador_vencedor//"%"/ }   @@"
  echo '    @@                        @@'
  echo '    @@ Quer tentar novamente? @@'
  echo '    @@ Sim(s)          Não(n) @@'
  echo '    @@                        @@'
  echo '    @@@@@@@@@@@@@@@@@@@@@@@@@@@@'
  read novamente
done
if [ $novamente == 'n' ]; then
  perguntar_se_querem_trocar_usuarios
else
  jogador_da_vez='X'
  tabuleiro=(- - - - - - - - -)
  principal
fi
}

velha(){
novamente=''
until [ ${#novamente} = 1 ] && [ $novamente == 's' -o $novamente == 'n' ]; do
  clear
  echo -e "\n\n\n\n\n"
  echo '    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@'
  echo '    @@                          @@'
  echo "    @@          VELHA!          @@"
  echo '    @@                          @@'
  echo '    @@ Querem tentar novamente? @@'
  echo '    @@ Sim(s)            Não(n) @@'
  echo '    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@'
  read novamente
done
if [ $novamente == 'n' ]; then
  perguntar_se_querem_trocar_usuarios
else
  jogador_da_vez='X'
  tabuleiro=(- - - - - - - - -)
  principal
fi
}

perguntar_se_querem_trocar_usuarios(){
reiniciar=''
until [ ${#reiniciar} = 1 ] && [ $reiniciar == 's' -o $reiniciar == 'n' ]; do
  clear
  echo -e "\n\n\n\n\n"
  echo '    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@'
  echo '    @@                          @@'
  echo "    @@    Alterar Jogadores?    @@"
  echo '    @@                          @@'
  echo '    @@   Sim(s)        Não(n)   @@'
  echo '    @@                          @@'
  echo '    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@'
  read reiniciar
done
if [ $reiniciar == 'n' ]; then
  sair
else
  jogador_da_vez='X'
  tabuleiro=(- - - - - - - - -)
  clear
  echo -e "\n\n\n"
  definicao_jogadores
fi
}

principal(){
opcao=''
until [ ${#opcao} = 1 ] && [ $opcao >\ '0' ] && [ $opcao \< ':' ]; do
  clear
  echo "  ===================================== Jogadas: ="
  echo "  ====== JOGO DA VELHA VERSÃO 9.0 =====  7/8/9   ="
  echo "  ========= por André Tissot ==========  4/5/6   ="
  echo "  =====================================  1/2/3   ="
  display_jogador1=${jogador[0]:0:8}"%%%%%%%%"; display_jogador1=${display_jogador1:0:8}
  display_jogador2=${jogador[1]:0:8}"%%%%%%%%"; display_jogador2=${display_jogador2:0:8}
  echo "  ==  (X)-${display_jogador1//"%"/ } == (O)-${display_jogador2//"%"/ }  ===  0-sair  ="
  numero_da_celula=6
  for numero_da_celula in 6 3 0; do
    for nivel in `seq 1 5`; do
      echo -n '           '
      mostrar_celula $numero_da_celula $nivel
      echo -n '|'
      mostrar_celula $(($numero_da_celula+1)) $nivel
      echo -n '|'
      mostrar_celula $(($numero_da_celula+2)) $nivel
      echo
    done
    if [ $numero_da_celula != 0 ]; then
      echo '        ooooooooooooooooooooooooooooooooooo'
    fi
  done
  verificar_termino
  if [ $jogador_da_vez = 'X' ]; then
    echo -n "Jogada de ${jogador[0]}:  "
  else
    echo -n "Jogada de ${jogador[1]}:  "
  fi
  read opcao
done
if [ $opcao -eq 0 ]; then
  sair
fi
escolheu_a $opcao
}

sair(){
  clear
  echo -e "\n\n\n\n\n"
  echo 'Espero que tenham gostado de jogar'
  sleep 2
  clear
  exit
}

escolheu_a(){
posicao=$(($1-1))
if [ ${tabuleiro[${posicao}]} != '-' ]; then
  echo 'Esse espaço já foi preenchido'
  sleep 1
else
  tabuleiro[$posicao]=$jogador_da_vez
  if [ $jogador_da_vez = 'X' ]; then
    jogador_da_vez='O'
  else
    jogador_da_vez='X'
  fi
fi
principal
}

introducao
