void FlowProseccoCount()
{
  StartCycle = digitalRead(StartPB);
  if ((StartCycle == HIGH) && (flowMilliLitres <= 60)) {
    digitalWrite(Pump1, HIGH);
    digitalWrite(Valve1, HIGH);
    Serial.println ("Start Prosecco");
  }
  else {
    digitalWrite(Pump1, LOW);
    digitalWrite(Valve1, LOW);
  }
}
