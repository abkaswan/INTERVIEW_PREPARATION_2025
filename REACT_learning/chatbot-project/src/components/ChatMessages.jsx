import { useEffect, useRef } from "react";
import {ChatMessage} from './ChatMessage';
import './ChatMessages.css';

function useAutoScroll(dependencies){
    const chatMessagesRef = useRef(null); // initial value
    // auto scroll to the bottom when chatMessages change
    useEffect(()=>{
      const containerElem = chatMessagesRef.current;
      if(containerElem){
        containerElem.scrollTop = containerElem.scrollHeight;
      }
    },[dependencies]);

    return chatMessagesRef;
}
function ChatMessages({chatMessages}) {

  let chatMessagesRef = useAutoScroll(chatMessages);

  return (
    <div className="chat-messages-container" ref={chatMessagesRef}>
      {chatMessages.map((chatMessage)=>{
            return (
              <ChatMessage 
                message= {chatMessage.message}
                sender= {chatMessage.sender}
                time= {chatMessage.time}
                key={chatMessage.id}
              />
            );
      })}
    </div>
  );
}

export default ChatMessages;