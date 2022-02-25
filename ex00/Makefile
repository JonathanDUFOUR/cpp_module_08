# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 20:22:45 by jodufour          #+#    #+#              #
#    Updated: 2022/02/24 22:39:09 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CXX			=	c++ -c
LINK		=	c++
MKDIR		=	mkdir -p
RM			=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME		=	ex00.out

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR		=	srcs/
OBJ_DIR		=	objs/
PRV_DIR		=	private/

######################################
#            SOURCE FILES            #
######################################
SRC			=	\
				main.cpp

######################################
#            OBJECT FILES            #
######################################
OBJ			=	${SRC:.cpp=.o}
OBJ			:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP			=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CPPFLAGS	=	-Wall -Wextra -Werror
CPPFLAGS	+=	-Wshadow
CPPFLAGS	+=	-std=c++98
CPPFLAGS	+=	-MMD -MP
CPPFLAGS	+=	-I${PRV_DIR}

LDFLAGS		=	

ifeq (${DEBUG}, 1)
	CPPFLAGS	+=	-g
	CPPFLAGS	+=	-DDEBUG=1
endif

#######################################
#                RULES                #
#######################################
${NAME}: ${OBJ}
	${LINK} $^ ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: ${SRC_DIR}%.cpp
	@${MKDIR} ${@D}
	${CXX} ${CPPFLAGS} $< ${OUTPUT_OPTION}

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

re: clean all

fre: fclean all

.PHONY: all clean fclean re fre
