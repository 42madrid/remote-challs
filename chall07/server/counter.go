package main

type Counter struct {
	c   chan uint64
	end chan struct{}
    i   uint64
}

func NewCounter() *Counter {
	counter := &Counter{
		c: make(chan uint64),
		end: make(chan struct{}),
		i: 1,
	}
	go counter.run()
	return counter
}

func (counter *Counter) C() <-chan uint64 {
	return counter.c
}

func (counter *Counter) Iter() uint64 {
	return <-counter.c
}

func (counter *Counter) Close() {
	counter.end <- struct{}{}
}

func (counter *Counter) run() {
	for {
		select {
		case counter.c <- counter.i:
			counter.i++
		case <-counter.end:
			close(counter.c)
			close(counter.end)
			return
		}
	}
}
