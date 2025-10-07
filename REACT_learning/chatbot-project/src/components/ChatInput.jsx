import { useState } from "react";
import dayjs from "dayjs";
import LoadingSpinner from '../assets/loading-spinner.gif'
import { Chatbot} from 'supersimpledev';
import './ChatInput.css';

export function ChatInput({chatMessages, setChatMessages}) {
  const [inputText,setInputText] = useState('');
  const [isLoading, setIsLoading] = useState(false);

  function saveInputText(event){
    setInputText(event.target.value);
    
  }
  async function sendMessage(){
    if(isLoading) return;
    const newChatMessages = [
      ...chatMessages,
      {
        message: inputText,
        sender: "user",
        time: dayjs().valueOf(),
        id: crypto.randomUUID()
      }
    ];
    setChatMessages(newChatMessages);
    setInputText(''); // clear the input field after sending the message
    
    // add loading message immediately
    setChatMessages([
      ...newChatMessages,
      {
        message: <img src={LoadingSpinner} alt="loading" className="loading-spinner" />,
        sender: "robot",
        time: dayjs().valueOf(),
        id: crypto.randomUUID()
      }
    ])
    setIsLoading(true);
    const response = await Chatbot.getResponseAsync(inputText);
    setIsLoading(false);

    setChatMessages([
      ...newChatMessages,
      {
        message: response,
        sender: "robot",
        time: dayjs().valueOf(),
        id: crypto.randomUUID()
      }
    ]);
  }

  return (
    <div className="chat-input-container">
      <input 
        placeholder="Send a message to Chatbot" 
        size="30"
        onChange={saveInputText}
        onKeyDown={(event)=>{
          if(event.key === 'Enter'){
            sendMessage();
          }
          else if(event.key === 'Escape'){
            setInputText('');
          }
        }}
        disabled={isLoading}
        value={inputText}
        className = "chat-input"
      />

      <button
        onClick={sendMessage}
        disabled={isLoading}
        className = "send-button"
      >
        {isLoading ? 'Sending...' : 'Send'}
      </button>
      {/* you can also write localStorage.setItem('messages',JSON.stringify([])) but because chatMessages is being updated, the useEffect in app component will run and the localStorage will be updated automatically */}
      <button 
        onClick={() => setChatMessages([])} 
        className="clear-button"
      >
        Clear
      </button>
    </div>
  );
}