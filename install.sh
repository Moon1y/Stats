#!/bin/bash

# Каталог, куда будет установлен исполняемый файл
INSTALL_DIR="$HOME/.local/bin"

# Проверяем, существует ли папка
if [ ! -d "$INSTALL_DIR" ]; then
  echo "Создаем каталог $INSTALL_DIR"
  mkdir -p "$INSTALL_DIR"
fi

echo "Компилируем программу..."
make

# Проверяем, что компиляция прошла успешно
if [ -f "./Stats/Stats/bin/x64/Release/Stats.out" ]; then
  echo "Копируем my_program в $INSTALL_DIR..."
  cp ./Stats/Stats/bin/x64/Release/Stats.out "$INSTALL_DIR"

  echo "Установка завершена. Теперь вы можете запускать программу командой my_program."
else
  echo "Ошибка: Компиляция не удалась. Исполняемый файл 'my_program' не найден."
  exit 1
fi