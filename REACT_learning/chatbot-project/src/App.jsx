import { useState , useEffect } from 'react';
import { Chatbot} from 'supersimpledev';
// no need to add jsx or js vite adds it automatically -- below is named export
import {ChatInput} from './components/ChatInput';
// this is how we can import without {} -- this is default export
import ChatMessages from './components/ChatMessages';
// this is a feature of vite , vite let's us import any type of life , a css file or a image file
import './App.css';

function App(){
  const [chatMessages, setChatMessages] = useState(
    JSON.parse(localStorage.getItem('messages')) || [{
      message : "hello chatbot",
      sender : "user",
      time : 1735168000000,
      id: 'id1' 
    },
    {
      message : "Hello! How can I help you?",
      sender : "robot",
      time : 1735168001000,
      id: 'id2'
    },
    {
      message : "can you get me today's date?",
      sender : "user",
      time : 1735168002000,
      id: 'id3'
    },
    {
      message : "Today is September 27",
      sender : "robot",
      time : 1735168003000,
      id: 'id4'
    }]
  );

  useEffect(()=>{
    localStorage.setItem('messages',JSON.stringify(chatMessages))
  },[chatMessages]);

  useEffect(() => {
    Chatbot.addResponses({"this is a test":"yes this is a test"})
  }, []);
    
    

  return (
    <div className="app-container">
      <ChatMessages 
        chatMessages={chatMessages}
      />
      <ChatInput 
        chatMessages={chatMessages}
        setChatMessages={setChatMessages}
      />
    </div>
  );
}


export default App
