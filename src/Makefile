include $(HOME)/Define.mk

OBJS= $(patsubst %.c,%.o,$(wildcard *.c))
OBJS+= $(patsubst %.cc,%.o,$(wildcard *.cc))

all:$(OBJS) $(LIB_PATH)/libmy.a $(LIB_PATH)/libmy.so

%.o:%.c
	$(CXX) -I$(INC) -c $^ $(CXXFLAGS) $(LIBGL)
%.o:%.cc
	$(CXX) -I$(INC) -c $^ $(CXXFLAGS) $(LIBGL)

$(LIB_PATH)/libmy.so:$(OBJS)
	$(CXX) -I$(INC) -fPIC -shared $^ -o $@ $(CXXFLAGS)

$(LIB_PATH)/libmy.a:$(OBJS)
	$(AR) $(ARFLAGS) $@ $^ 

clean:
	rm -rf $(OBJS)
