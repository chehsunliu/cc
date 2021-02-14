package zz

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestHello(t *testing.T) {
	assert.True(t, isHappy(19))
	assert.False(t, isHappy(4))
}
