import telebot
from telebot import types
bot = telebot.TeleBot('7373320672:AAF0WQ9YR7Ko73BWTyOOFNTC8kJZkoMBqPM')

@bot.message_handler(commands=['start'])
def get_text_messages(message):
    markup = types.ReplyKeyboardMarkup(resize_keyboard=True)
    btn1 = types.KeyboardButton("on")
    btn2 = types.KeyboardButton("off")
    markup.add(btn1, btn2)
    bot.send_message(message.chat.id, text="Открыть или закрыть ворота?", reply_markup=markup)

bot.polling(none_stop=True)
