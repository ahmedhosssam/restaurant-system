CXX = g++
CXXFLAGS = -Wall -std=c++11

SRCS = main.cpp src/Delivery.cpp  src/Ingredient.cpp  src/InRestaurant.cpp  src/Manager.cpp  src/Meal.cpp  src/Menu.cpp  src/Order.cpp  src/Restaurant.cpp  src/Stock.cpp  src/Table.cpp  src/TakeAway.cpp	
OBJS = $(SRCS:.cpp=.o)

TARGET = a.out

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -r $(TARGET)
